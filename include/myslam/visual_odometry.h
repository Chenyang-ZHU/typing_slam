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
  VisualOdometry(const std::string &config_file_path);
  ~VisualOdometry();

  bool Init();
  void Run();

  bool addFrame(Frame::Ptr frame);

 private:
  Tracker::Ptr tracker_;
  Visualizer::Ptr visualizer_;
  Map::Ptr map_;
  Dataset::Ptr dataset_;
  OdomStatus state_;
  std::string config_file_path_;

  SlamConfigs configs_;
};
}  // namespace typingslam
#endif