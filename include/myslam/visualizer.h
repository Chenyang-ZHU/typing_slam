#ifndef TYPINGSLAM_VISUALIZER_H
#define TYPINGSLAM_VISUALIZER_H

#include "common_include.h"
#include "frame.h"

namespace typingslam {

class Visualizer {
 public:
  typedef std::shared_ptr<Visualizer> Ptr;

  void AddFrame(Frame::Ptr frame);
};
}  // namespace typingslam
#endif