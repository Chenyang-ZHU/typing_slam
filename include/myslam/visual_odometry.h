#ifndef TYPINGSLAM_VISUALODOMETRY_H
#define TYPINGSLAM_VISUALODOMETRY_H

#include "config.h"
#include "dataset.h"
#include "map.h"
#include "tracker.h"
#include "visualizer.h"

namespace typingslam {
class VisualOdometry {
 public:
  EIGEN_MAKE_ALIGNED_OPERATOR_NEW;
  typedef std::shared_ptr<VisualOdometry> Ptr;
  VisualOdometry(const std::string &config_file_path);
  ~VisualOdometry();

  bool Init();
  void Run();
  bool Step();

  bool addFrame(Frame::Ptr frame);

 private:
  Tracker::Ptr tracker_;
  Visualizer::Ptr visualizer_;
  Map::Ptr map_;
  Dataset::Ptr dataset_;
  std::string config_file_path_;
  SlamConfigs configs_;
};
}  // namespace typingslam
#endif