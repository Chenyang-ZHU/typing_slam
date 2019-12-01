#ifndef TYPINGSLAM_FRAME_H
#define TYPINGSLAM_FRAME_H

#include "common_include.h"
#include "camera.h"

namespace typingslam{
	
	class Frame{
	public:
		typedef std::shared_ptr<Frame> Ptr;
		unsigned long id_; // id of this frame
		double time_stamp_;
		SE3 T_c_w_; 				// transform from world to camera
		Camera::Ptr camera_;    // Pinhole RGB-D camera model
		Mat color_, depth_;     // color and depth image

	public: // data members
		Frame();
		Frame( long id, double time_stamp = 0, SE3 T_c_w = SE3(), Camera::Ptr camera = nullptr, Mat color = Mat(), Mat depth = Mat());
		~Frame();
	
		// factory function
		static Frame::Ptr createFrame();

		// find the depth in depth map
		double findDepth( const cv::KeyPoint& kp);

		// get camera center
		Vector3d getCamCenter() const;

		//check if a point is in this frame
		bool isInFrame( const Vector3d& pt_world);


	};



}

#endif