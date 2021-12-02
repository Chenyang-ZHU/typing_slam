
#include "myslam/visual_odometry.h"

#include <algorithm>
#include <boost/timer.hpp>
#include <chrono>
#include <opencv2/calib3d/calib3d.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

namespace typingslam {

VisualOdometry::VisualOdometry(const std::string &config_file_path)
    : config_file_path_(config_file_path), map_(new Map) {}

VisualOdometry::~VisualOdometry() {}

bool VisualOdometry::Init() {
  Config slam_config(config_file_path_);
  configs_ = slam_config.configs_;
  dataset_ = Dataset::Ptr(new Dataset(configs_.dataset_dir));
  dataset_->Init();
  return true;
}

void VisualOdometry::Run() {
  while (1) {
    std::cout << "VO is running" << std::endl;
    if (Step() == false) {
      break;
    }
  }
  std::cout << "VO exit!" << std::endl;
}

bool VisualOdometry::Step() {
  Frame::Ptr frame = dataset_->NextFrame();
  if (frame == nullptr) {
    std::cerr << "frame is null!" << std::endl;
  } else
    std::cerr << "frame:" << frame << std::endl;

  if (frame->image_.empty()) std::cerr << "frame image is null!" << std::endl;
  // cv::Mat img = frame->image_.clone();
  cv::imshow("frame", frame->image_);
  cv::waitKey(0);
  // bool success = tracker_->AddFrame(frame);
  return true;
}
}  // namespace typingslam