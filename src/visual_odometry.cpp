#include "myslam/visual_odometry.h"

#include <algorithm>
#include <boost/timer.hpp>
#include <opencv2/calib3d/calib3d.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

#include "myslam/config.h"

namespace typingslam {

VisualOdometry::VisualOdometry(const std::string &config_file_path)
    : state_(INITIALIZING), map_(new Map) {}

VisualOdometry::~VisualOdometry() {}

bool VisualOdometry::Init() {
  // read from config file
  if (Config::SetParameterFile(config_file_path_) == false) {
    return false;
  }
}

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

bool Init() {}

}  // namespace typingslam