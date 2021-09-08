/*
 * @Author: your name
 * @Date: 2021-08-17 21:36:36
 * @LastEditTime: 2021-08-17 22:24:06
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /typing_slam/include/frame.h
 */
#ifndef TYPINGSLAM_FRAME_H
#define TYPINGSLAM_FRAME_H

#include "camera.h"
#include "common_include.h"

namespace typingslam {

class Frame {
 public:
  typedef std::shared_ptr<Frame> Ptr;
  unsigned long id_;  // id of this frame
  double time_stamp_;
  Sophus::SE3<double> T_c_w_;  // transform from world to camera
  Camera::Ptr camera_;         // Pinhole RGB-D camera model
  Mat color_, depth_;          // color and depth image

 public:  // data members
  Frame();
  Frame(long id, double time_stamp = 0, Sophus::SE3<double> T_c_w = Sophus::SE3<double>(),
        Camera::Ptr camera = nullptr, Mat color = Mat(), Mat depth = Mat());
  ~Frame();

  // factory function
  static Frame::Ptr createFrame();

  // find the depth in depth map
  double findDepth(const cv::KeyPoint& kp);

  // get camera center
  Vector3d getCamCenter() const;

  // check if a point is in this frame
  bool isInFrame(const Vector3d& pt_world);
};

}  // namespace typingslam

#endif