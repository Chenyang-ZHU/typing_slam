#include "tracker.h"

namespace typingslam {

Tracker() {
  orb_ = cv::ORB::create(num_of_features_, scale_factor_, level_pyramid_);
}

void Tracker::AddFrame(Frame::Ptr frame);

}  // namespace typingslam