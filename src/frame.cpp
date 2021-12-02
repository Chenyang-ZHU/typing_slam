#include "myslam/frame.h"

namespace typingslam {

Frame::Frame(long id, double time_stamp, Sophus::SE3<double> T_c_w,
             Camera::Ptr camera, Mat image)
    : id_(id),
      time_stamp_(time_stamp),
      T_c_w_(T_c_w),
      camera_(camera),
      image_(image) {}

Frame::Ptr Frame::CreateFrame() {
  static long factory_id = 0;
  Frame::Ptr frame(new Frame);
  frame->id_ = factory_id++;
  return frame;
}

// double Frame::FindDepth(const cv::KeyPoint& kp) {
//   // int x = cvRound(kp.pt.x);
//   // int y = cvRound(kp.pt.y);
//   // ushort d = depth_.ptr<ushort>(y)[x];

//   // if ( d != 0 )
//   // {
//   // 	return double(d)/camera_->depth_scale_;
//   // }
//   // else
//   // {
//   // 	//check the nearby points
//   // 	int dx[4] = {-1, 0, 1, 0};
//   // 	int dy[4] = {0, -1, 0, 1};
//   // 	for (int i = 0; i<4; i++)
//   // 	{
//   // 		d = depth_.ptr<ushort>( y+dy[i] )[x+dx[i]];
//   // 		if ( d != 0){
//   // 			return double(d)/camera_->depth_scale_;
//   // 		}
//   // 	}
//   // }
//   // return -1.0;
// }

// Vector3d Frame::GetCamCenter() const { return T_c_w_.inverse().translation();
// }

// bool Frame::IsInFrame(const Vector3d& pt_world) {
//   Vector3d p_cam = camera_->world2camera(pt_world, T_c_w_);
//   if (p_cam(2, 0) < 0) return false;
//   Vector2d pixel = camera_->world2pixel(pt_world, T_c_w_);

//   return pixel(0, 0) > 0 && pixel(1, 0) > 0 && pixel(0, 0) < image_.cols &&
//          pixel(1, 0) < image_.rows;
// }

}  // namespace typingslam