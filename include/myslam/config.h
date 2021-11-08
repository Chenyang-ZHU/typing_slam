#ifndef TYPINGSLAM_CONFIG_H
#define TYPINGSLAM_CONFIG_H

#include "common_include.h"

namespace typingslam {

class Config {
 private:
  static std::shared_ptr<Config> config_;
  cv::FileStorage file_;

  Config() {}  // private constructor makes a singleton

 public:
  ~Config();  // close the file when desconstructing

  // set a new config file
  static bool SetParameterFile(const std::string& filename);

  // access the parameter vvalues
  template <typename T>
  static T get(const std::string& key) {
    return T(Config::config_->file_[key]);
  }
};
}  // namespace typingslam
#endif