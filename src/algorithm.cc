#include "myslam/algorithm.h"

namespace typingslam {
namespace algorithm {
void Triangulation(const std::vector<cv::KeyPoint> &cur_keypoints,
                   const std::vector<cv::KeyPoint> &ref_keypoints,
                   std::vector<Sophus::Vector3d> &map_points) {
  map_points.clear();
}

}  // namespace algorithm
}  // namespace typingslam