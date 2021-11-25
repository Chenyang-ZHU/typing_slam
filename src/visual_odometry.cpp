
#include "myslam/visual_odometry.h"

#include <algorithm>
#include <boost/timer.hpp>
#include <opencv2/calib3d/calib3d.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

#include "myslam/config.h"
namespace typingslam {

VisualOdometry::VisualOdometry(const std::string &config_file_path)
    : config_file_path_(config_file_path),
      state_(INITIALIZING),
      map_(new Map) {}

VisualOdometry::~VisualOdometry() {}

bool VisualOdometry::Init() {
  // read from config file
  if (Config::SetParameterFile(config_file_path_) == false) {
    std::cerr << "config file path wrong!" << std::endl;
    return false;
  }
  std::string dataset_path = Config::Get<std::string>("dataset");
  std::cerr << dataset_path << std::endl;

  dataset_ = Dataset::Ptr(new Dataset(Config::Get<std::string>("dataset")));

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