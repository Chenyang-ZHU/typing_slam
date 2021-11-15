#ifndef TYPINGSLAM_TRACKER_H
#define TYPINGSLAM_TRACKER_H

#include "algorithm.h"
#include "common_include.h"
#include "feature.h"
#include "frame.h"
#include "map.h"
#include "visualizer.h"

namespace typingslam {
class Tracker {
 public:
  typedef std::shared_ptr<Tracker> Ptr;
  Tracker();
  ~Tracker();
  void AddFrame(Frame::Ptr frame);

  // where to put initialized 3d map points, which need to be inserted into
  // map_;
  void Initialize();
  void UpdateReference();
  void TrackLastFrame();
  void Relocalize();

 private:
  void ExtractFeatures();
  void MatchFeatures();
  void EstimatePose();
  void Insertkeyframe();

 private:
  Map::Ptr map_;
  Visualizer::Ptr visualizer_;

  Camera::Ptr camera_;  // Pinhole RGB-D camera model
  Frame::Ptr ref_frame_ = nullptr;
  Frame::Ptr cur_frame_ = nullptr;
  Frame::Ptr ini_frame_ = nullptr;
  cv::Ptr<cv::ORB> orb_;  // orb detector and computer
  int num_of_features_;
  int scale_factor_;
  int level_pyramid_;
};
}  // namespace typingslam
#endif