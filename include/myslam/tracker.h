#ifndef TYPINGSLAM_TRACKER_H
#define TYPINGSLAM_TRACKER_H

#include "frame.h"
namespace typingslam {
class Tracker {
 public:
  typedef std::shared_ptr<Tracker> Ptr;
  Tracker();
  ~Tracker();
  void AddFrame(Frame::Ptr frame);
  void UpdateReference();

 private:
  void ExtractFeatures();
  void MatchFeatures();
  void EstimatePose();

 private:
  Frame::Ptr ref_frame_;
  Frame::Ptr cur_frame_;
  orb_;
};
}  // namespace typingslam
#endif