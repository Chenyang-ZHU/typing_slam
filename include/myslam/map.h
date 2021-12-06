#ifndef TYPINGSLAM_MAP_H
#define TYPINGSLAM_MAP_H

#include "common_include.h"
#include "frame.h"
#include "mappoint.h"

namespace typingslam {

class Map {
 public:
  typedef std::shared_ptr<Map> Ptr;
  typedef std::unordered_map<unsigned long, MapPoint::Ptr> MapPoints;
  typedef std::unordered_map<unsigned long, Frame::Ptr> KeyFrames;

  MapPoints map_points_;
  KeyFrames keyframes_;  // all keyframes
  MapPoints active_map_points_;
  KeyFrames active_keyframes_;

  Map() {}

  void insertKeyFrame(Frame::Ptr frame);
  void insertMapPoint(MapPoint::Ptr map_point);

  MapPoints GetActiveMapPoints() { return active_map_points_; }
  KeyFrames GetActiveKeyFrames() { return active_keyframes_; }
};

}  // namespace typingslam
#endif