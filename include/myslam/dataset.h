#ifndef TYPINGSLAM_DATASET_H
#define TYPINGSLAM_DATASET_H
#include <dirent.h>
#include <limits.h>

#include <algorithm>
#include <fstream>
#include <iostream>

#include "common_include.h"
#include "frame.h"
namespace typingslam {
class Dataset {
 public:
  EIGEN_MAKE_ALIGNED_OPERATOR_NEW;
  typedef std::shared_ptr<Dataset> Ptr;
  Dataset(const std::string dataset_path);
  void Init();
  std::shared_ptr<Frame> NextFrame();

 private:
  void GetFileNames(const std::string &path,
                    std::vector<std::string> &file_names);

 private:
  int image_index_ = 0;
  const std::string dataset_path_;
  std::string image_path_;
  std::string calib_file_;

  std::vector<std::string> file_names_;
};
}  // namespace typingslam
#endif