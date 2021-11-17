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
  typedef std::shared_ptr<Dataset> Ptr;
  Dataset(const std::string dataset_path);
  ~Dataset();
  void Init();
  Frame::Ptr NextFrame();

 private:
  void GetFileNames(const std::string &path,
                    std::vector<std::string> &file_names);

 private:
  int image_index_ = 0;
  const std::string dataset_path_;
  std::vector<std::string> file_names_;
};
}  // namespace typingslam
#endif