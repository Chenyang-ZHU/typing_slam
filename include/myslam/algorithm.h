#ifndef TYPINGSLAM_ALGORITHM_H
#define TYPINGSLAM_ALGORITHM_H

#include "common_include.h"
#include "feature.h"

namespace typingslam {
namespace algorithm {
void Triangulation(const std::vector<cv::KeyPoint> cur_keypoints,
                   const std::vector<cv::KeyPoint> ref_keypoints,
                   const std::vector<Sophus::Vector3d> map_points);
}
}  // namespace typingslam

#endif