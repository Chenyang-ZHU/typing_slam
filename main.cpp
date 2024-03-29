//
// Created by CHENYANG ZHU on 9/14/20.
//
#include <iostream>

#include "include/myslam/visual_odometry.h"

int main(int argc, char *argv[]) {
  std::cout << "hello slam" << std::endl;
  std::cout << argv[1] << std::endl;

  std::string config_path = argv[1];
  std::cout << config_path << std::endl;

  typingslam::VisualOdometry vo(config_path);
  vo.Init();
  vo.Run();
}