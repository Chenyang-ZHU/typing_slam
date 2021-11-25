
#include "myslam/visual_odometry.h"

#include <algorithm>
#include <boost/timer.hpp>
#include <opencv2/calib3d/calib3d.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

namespace typingslam {

VisualOdometry::VisualOdometry(const std::string &config_file_path)
    : config_file_path_(config_file_path),
      state_(INITIALIZING),
      map_(new Map) {}

VisualOdometry::~VisualOdometry() {}

bool VisualOdometry::Init() {
  Config slam_config(config_file_path_);
  configs_ = slam_config.configs_;
  dataset_ = Dataset::Ptr(new Dataset(configs_.dataset_dir));
  return true;
}

void VisualOdometry::Run() {}

bool VisualOdometry::addFrame(Frame::Ptr frame) {
  tracker_->AddFrame(frame);
  switch (state_) {
    case INITIALIZING: {
      Init();
      break;
    }
    case GOOD: {
      Run();
    }
    case BAD: {
      tracker_->Relocalize();
    }
  }
  return true;
}

}  // namespace typingslam