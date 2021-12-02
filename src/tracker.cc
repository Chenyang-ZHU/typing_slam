#include "myslam/tracker.h"
namespace typingslam {

Tracker::Tracker() : state_(INITIALIZING) {
  orb_ = cv::ORB::create(num_of_features_, scale_factor_, level_pyramid_);
}

bool Tracker::AddFrame(typingslam::Frame::Ptr frame) {
  cur_frame_ = frame;
  switch (state_) {
    case INITIALIZING: {
      Initialize();
      break;
    }
    case GOOD: {
      TrackLastFrame();
    }
    case BAD: {
      Relocalize();
    }
  }
  return true;
}

void Tracker::UpdateReference() { ref_frame_ = cur_frame_; }

void Tracker::TrackLastFrame() {}

void Tracker::Initialize() {
  if (!ini_frame_)
    ini_frame_ = cur_frame_;
  else {
    ref_frame_ = cur_frame_;
    // use ini_frame_ and ref_frame_ to initilize map
    std::vector<Sophus::Vector3d> map_points;
    algorithm::Triangulation(ini_frame_->key_points_, ref_frame_->key_points_,
                             map_points);
    long id = map_->map_points_.size();
    for (auto p : map_points) {
      id++;
      Sophus::Vector3d norm = p;
      MapPoint::Ptr map_point =
          std::shared_ptr<MapPoint>(new MapPoint(id, p, norm));
      map_->insertMapPoint(map_point);
    }
    map_->insertKeyFrame(ini_frame_);
    state_ = GOOD;
  }
}

void Tracker::ExtractFeatures() {
  orb_->detect(cur_frame_->image_, cur_frame_->key_points_,
               cur_frame_->descriptor_);
  for (auto kp : cur_frame_->key_points_) {
    Feature::Ptr feature =
        std::shared_ptr<Feature>(new Feature(cur_frame_, kp));
    cur_frame_->features_.emplace_back(feature);
  }
}

void Tracker::MatchFeatures() {
  cv::BFMatcher matcher(cv::NORM_L2);
  matcher.match(cur_frame_->descriptor_, ref_frame_->descriptor_,
                cur_frame_->matches_);
}
void Tracker::EstimatePose() {
  std::vector<cv::Point> cur_kps, ref_kps;
  for (auto match : cur_frame_->matches_) {
    cur_kps.emplace_back(
        cur_frame_->features_[match.queryIdx].get()->position_.pt);
    ref_kps.emplace_back(
        ref_frame_->features_[match.queryIdx].get()->position_.pt);
  }
  cv::Mat E = cv::findEssentialMat(cur_kps, ref_kps, camera_->fx_,
                                   camera_->principal_point_, cv::RANSAC);
  cv::recoverPose(E, cur_kps, ref_kps, camera_->K_, cur_frame_->R_relative_,
                  cur_frame_->t_relative_);
  Eigen::Matrix3d R;
  Eigen::Vector3d t;
  cv::cv2eigen(cur_frame_->R_relative_, R);
  cv::cv2eigen(cur_frame_->t_relative_, t);
  cur_frame_->T_c_w_ = Sophus::SE3d(R, t);
}

void Tracker::Relocalize() {}

}  // namespace typingslam