#pragma once
#ifndef TYPINGSLAM_CONFIG_H
#define TYPINGSLAM_CONFIG_H

#include "myslam/common_include.h"

namespace typingslam {

class Config {
 public:
  Config(const std::string& filename) {
    cv::FileStorage file_ =
        cv::FileStorage(filename.c_str(), cv::FileStorage::READ);
    if (!file_.isOpened()) {
      std::cerr << "parameter file " << filename << " does not exist."
                << std::endl;
    } else {
      std::cout << "file is ok: " << std::endl;
    }
    int num;
    file_["num_features"] >> num;
    std::cout << num << std::endl;
    file_["dataset_dir"] >> configs_.dataset_dir;
  }             // private constructor makes a singleton
  ~Config() {}  // close the file when desconstructing

 public:
  SlamConfigs configs_;
  // cv::FileStorage file_;
};
}  // namespace typingslam
#endif