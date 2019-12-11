#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/calib3d/calib3d.hpp>
#include <algorithm>
#include <boost/timer.hpp>

#include "config.h"
#include "visual_odometry.h"

namespace typingslam{

	VisualOdometry::VisualOdometry():
		state_(INITIALIZING), ref_( nullptr ), curr_( nullptr ), map_( new Map ), num_lost_( 0 ), num_inliers_( 0 )
	{

		
	}








}