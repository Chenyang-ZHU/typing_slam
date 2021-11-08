#ifndef TYPINGSLAM_MAP_H
#define TYPINGSLAM_MAP_H

#include "common_include.h"
#include "frame.h"
#include "mappoint.h"

namespace typingslam {

class Map {
 public:
  typedef std::shared_ptr<Map> Ptr;
  std::unordered_map<unsigned long, MapPoint::Ptr> map_points_;
  std::unordered_map<unsigned long, Frame::Ptr> keyframes_;  // all keyframes

  Map() {}

  void insertKeyFrame(Frame::Ptr frame);
  void insertMapPoint(MapPoint::Ptr map_point);
};

}  // namespace typingslam
#endif