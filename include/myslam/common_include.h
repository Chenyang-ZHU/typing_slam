/*
 * @Author: your name
 * @Date: 2021-08-17 21:36:36
 * @LastEditTime: 2021-08-17 22:13:27
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /typing_slam/include/common_include.h
 */
#ifndef TYPINGSLAM_COMMOM_INCLUDE_H
#define TYPINGSLAM_COMMOM_INCLUDE_H

// define the commonly included file to avoid a long include list

// for Eigen
#include <Eigen/Core>
#include <Eigen/Geometry>
using Eigen::Vector2d;
using Eigen::Vector3d;

// for Sophus
#include <sophus/se3.hpp>
#include <sophus/so3.hpp>
using Sophus::SE3;

// for cv
#include <opencv2/core/core.hpp>
using cv::Mat;

// std
#include <iostream>
#include <list>
#include <map>
#include <memory>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>

// basic structure
enum OdomStatus { INITIALIZING = 0, GOOD = 1, BAD = 2 };

#endif
