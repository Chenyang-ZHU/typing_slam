#ifndef TYPINGSLAM_MAPPOINT_H
#define TYPINGSLAM_MAPPOINT_H

#include "common_include.h"

namespace typingslam {

class Frame;
class MapPoint {
 public:
  typedef std::shared_ptr<MapPoint> Ptr;
  unsigned long id_;    // ID
  Vector3d pos_;        // position in the world
  Vector3d norm_;       // normal of viewing direction
  Mat descriptor_;      // descriptor of matching
  int observed_times_;  // being observed by feature matching algo
  int correct_times_;   // being an inliner in pose estimation

  MapPoint();
  MapPoint(long id, Vector3d position, Vector3d norm);

  // factory function
  static MapPoint::Ptr createMapPoint();
};
}  // namespace typingslam
#endif