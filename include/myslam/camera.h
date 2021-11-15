/*
 * @Author: your name
 * @Date: 2021-08-17 21:36:36
 * @LastEditTime: 2021-08-17 22:21:44
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /typing_slam/include/camera.h
 */
#ifndef TYPINGSLAM_CAMERA_H
#define TYPINGSLAM_CAMERA_H

#include "common_include.h"

namespace typingslam {

// pinhole RGB-D camera model
class Camera {
 public:
  typedef std::shared_ptr<Camera> Ptr;

  float fx_, fy_, cx_, cy_, depth_scale_;
  cv::Point principal_point_;
  cv::Mat K_;  // camera projection matrix
  // constructor
  Camera();
  Camera(float fx, float fy, float cx, float cy, float depth_scale = 0)
      : fx_(fx), fy_(fy), cx_(cx), cy_(cy), depth_scale_(depth_scale) {}

  // coordinate transform: world, camera, pixel
  Vector3d world2camera(const Vector3d& p_w, const Sophus::SE3<double>& T_c_w);
  Vector3d camera2world(const Vector3d& p_c, const Sophus::SE3<double>& T_c_w);
  Vector2d camera2pixel(const Vector3d& p_c);
  Vector3d pixel2camera(const Vector2d& p_p, double depth = 1);
  Vector3d pixel2world(const Vector2d& p_p, const Sophus::SE3<double>& T_c_w,
                       double depth = 1);
  Vector2d world2pixel(const Vector3d& p_w, const Sophus::SE3<double>& T_c_w);
};
}  // namespace typingslam

#endif  // TYPINGSLAM_CAMERA_H