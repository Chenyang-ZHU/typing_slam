#ifndef TYPINGSLAM_FEATURE_H
#define TYPINGSLAM_FEATURE_H
#include "common_include.h"
#include "frame.h"
#include "mappoint.h"
namespace typingslam {
class Feature {
 public:
  Feature() {}
  Feature(std::shared_ptr<Frame> frame, const cv::KeyPoint &kp)
      : frame_(frame), position_(kp) {}

 public:
  typedef std::shared_ptr<Feature> Ptr;
  std::weak_ptr<Frame> frame_;         // frame contains this feature
  std::weak_ptr<MapPoint> map_point_;  // related map point
  cv::KeyPoint position_;              // feature pixel position

  bool is_outlier_ = false;  // is outlier
};

}  // namespace typingslam

#endif
