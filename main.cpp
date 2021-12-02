//
// Created by CHENYANG ZHU on 9/14/20.
//
#include <iostream>

#include "include/myslam/frame.h"
#include "include/myslam/visual_odometry.h"

void GetOneFrame() {
  typingslam::Dataset::Ptr dataset_(
      new typingslam::Dataset("/home/chenyang/Documents/kitti/odometry/04"));
  dataset_->Init();
  typingslam::Frame::Ptr frame = dataset_->NextFrame();
  std::cout << frame << std::endl;
}

int main(int argc, char *argv[]) {
  GetOneFrame();
  std::cout << "hello slam" << std::endl;
  std::string config_path = argv[1];
  std::cout << config_path << std::endl;
  typingslam::VisualOdometry::Ptr vo(
      new typingslam::VisualOdometry(config_path));
  bool initial = vo->Init();
  bool step = vo->Step();
}