#include "myslam/config.h"

bool typingslam::Config::SetParameterFile(const std::string& filename) {
  if (config_ == nullptr) config_ = std::shared_ptr<Config>(new Config);
  config_->file_ = cv::FileStorage(filename.c_str(), cv::FileStorage::READ);

  if (config_->file_.isOpened() == false) {
    std::cerr << "parameter file " << filename << "does not exist."
              << std::endl;
    config_->file_.release();
    return false;
  }
  return true;
}

typingslam::Config::~Config() {
  if (file_.isOpened()) file_.release();
}

namespace typingslam {
std::shared_ptr<Config> Config::config_ = nullptr;
}