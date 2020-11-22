#ifndef TYPINGSLAM_CAMERA_H
#define TYPINGSLAM_CAMERA_H

#include "typingslam/common_include.h"

namespace typingslam{
	
	// pinhole RGB-D camera model
	class Camera{

	public:
		typedef std::shared_ptr<Camera> CameraPtr;

		float fx_, fy_, cx_, cy_, depth_scale_;

		//constructor
		Camera();
		Camera(float fx_, float fy_, float cx_, float cy_, float depth_scale=0):
			fx_(fx), fy_(fy), cx_(cx), cy_(cy), depth_scale_(depth_scale){}

		// coordinate transform: world, camera, pixel
		Vector3d world2camera( const Vector3d& p_w, const SE3& T_c_w);
		Vector3d camera2world( const Vector3d& p_c, const SE3& T_c_w);
		Vector2d camera2pixel( const Vector3d& p_c);
		Vector3d pixel2camera( const Vector2d& p_p, double depth=1);
		Vector3d pixel2world( const Vector2d& p_p, const SE3& T_c_w, double depth=1);
		Vector2d world2pixel( const Vector3d& p_w, const SE3& T_c_w);

	};
} 

#endif // TYPINGSLAM_CAMERA_H