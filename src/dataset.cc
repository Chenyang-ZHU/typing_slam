#include "myslam/dataset.h"
namespace typingslam {

Dataset::Dataset(const std::string dataset_path)
    : dataset_path_(dataset_path) {}

void Dataset::Init() {
  image_path_ = dataset_path_ + "/image_3";
  GetFileNames(image_path_, file_names_);
}

Frame::Ptr Dataset::NextFrame() {
  std::string file_name = image_path_ + "/" + file_names_[image_index_];
  auto frame = Frame::CreateFrame();
  // todo: why has to create? why auto? return Frame::Ptr is wrong
  // cv::Mat img = cv::imread(file_name);
  // frame->image_ = img;
  std::cout << frame << std::endl;
  return frame;
}

void Dataset::GetFileNames(const std::string &path,
                           std::vector<std::string> &file_names) {
  DIR *pDir;
  struct dirent *ptr;
  if (!(pDir = opendir(path.c_str()))) return;
  while ((ptr = readdir(pDir)) != 0) {
    if (strcmp(ptr->d_name, ".") != 0 && strcmp(ptr->d_name, "..") != 0)
      file_names.emplace_back(ptr->d_name);
  }
  closedir(pDir);
  std::sort(file_names.begin(), file_names.end());
}

}  // namespace typingslam