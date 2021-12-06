/*
 * @Author: your name
 * @Date: 2021-08-17 21:36:36
 * @LastEditTime: 2021-08-17 22:24:06
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /typing_slam/include/frame.h
 */
#pragma once
#ifndef TYPINGSLAM_FRAME_H
#define TYPINGSLAM_FRAME_H

#include "camera.h"
#include "common_include.h"
namespace typingslam {
struct Feature;
struct Frame {
 public:
  EIGEN_MAKE_ALIGNED_OPERATOR_NEW;
  typedef std::shared_ptr<Frame> Ptr;
  unsigned long id_;  // id of this frame
  double time_stamp_;
  Sophus::SE3d T_c_w_;  // transform from world to camera
  Camera::Ptr camera_;  // Pinhole RGB-D camera model
  Mat image_;           // color image

  std::vector<std::shared_ptr<Feature>> features_;
  std::vector<cv::KeyPoint> key_points_;
  cv::Mat descriptor_;
  std::vector<cv::DMatch> matches_;  // match relation to ref
  cv::Mat R_relative_;
  cv::Mat t_relative_;

 public:  // data members
  Frame() {}
  Frame(long id, double time_stamp, Sophus::SE3<double> T_c_w,
        Camera::Ptr camera, Mat image);
  //   ~Frame(){};

  Sophus::SE3d Pose() { return T_c_w_; }

  // factory function
  static std::shared_ptr<Frame> CreateFrame();

  //   // find the depth in depth map
  //   double FindDepth(const cv::KeyPoint& kp);

  //   // get camera center
  //   Vector3d GetCamCenter() const;

  //   // check if a point is in this frame
  //   bool IsInFrame(const Vector3d& pt_world);
};

}  // namespace typingslam

#endif