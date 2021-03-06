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
		num_of_features_ 	= Config::get<int> ( "number_of_features" );
		scale_factor_ 		= Config::get<double> ( "scale_factor" );
		level_pyramid_		= Config::get<int>("level+_pyramid");
		match_ratio_		= Config::get<float>("match_ratio");
		max_num_lost_		= Config::get<float>("max_num_lost");
		min_inliers_		= Config::get<int>("min_inliers");
		key_frame_min_rot	= Config::get<double>("keyframe_rotation");
		key_frame_min_trans	= Config::get<double>("keyframe_translation");
		orb_ = cv::ORB::create ( num_of_features_, scale_factor_, level_pyramid_ );
	}


	VisualOdometry::~VisualOdometry()
	{

	}


	bool VisualOdometry::addFrame ( Frame::Ptr frame)
	{
		switch( state_ )
		{
			case INITIALIZING:
			{
				state_ = OK;
				curr_ = ref_ = frame;
				map_->insertKeyFrame( frame );
				// extract features from first frame
				extractKeyPoints();			// functions in the same class can be called by each other
				computeDescriptors();
				// computer the 3d position of features in ref frame
				setRef3DPoints();
				break;
			}

			case OK:
			{
				curr_ = frame;
				extractKeyPoints();
				computeDescriptors();
				featureMatching();
				poseEstimationPnP();
				if( checkEstimatedPose() == true ) // a good estimation
				{
					curr_->T_c_w_ = T_c_r_estimated_ * ref_->T_c_w_;  // T_c_w = T_c_r * T_r_w
					ref_ = curr_;
					setRef3DPoints();
					num_lost_ = 0;
					if (checkKeyFrame() == true ) // is a key-frame
					{
						addKeyFrame();
					}
				}
				else // bad estimation due to various reasons
				{
					num_lost_++;
					if ( num_lost_ > max_num_lost_)
					{
						state_ = LOST;
					}
					return false;
				}
				break;
			}

			case LOST:
			{
				cout<<"############vo has lost############"<<endl;
				break;
			}
		}
		return true;
	}


	void VisualOdometry::extractKeyPoints()
	{
		orb_->detect ( curr_->color_, keypoints_curr_);
	}


	void VisualOdometry::computeDescriptors()
	{
		orb_->compute ( curr_->color_, keypoints_curr_, descriptors_curr_);
	}


	void VisualOdometry::featureMatching()
	{
		// match desp_ref and desp_curr, use OpenCV's brute force match
		vector<cv::DMatch> matches;
		cv::BFMatcher matcher ( cv::NORM_HAMMING );
		matcher.match( descriptors_ref_, descriptors_curr_, matches );
		// select the best matches
		float min_dis = std::min_element(
							matches.begin(), matches.end(),
							[] ( const cv::DMatch& m1, const cv::DMatch& m2)
							{
								return m1.distance < m2.distance;
							} )->distance;

		feature_matches_.clear();
		for ( cv::DMatch& m : matches )
		{
			if ( m.distance < max<float>( min_dis*match_ratio_, 30.0) )
			{
				feature_matches_.push_back( m );
			}
		}
		cout<<"## good matches num: "<< feature_matches_.size()<<endl;
	}


	void VisualOdometry::setRef3DPoints()
	{
		// select the features with depth measurements
		pts_3d_ref_.clear();
		descriptors_ref_ = Mat();
		for ( size_t i = 0; i < keypoints_curr_.size(); i++ )
		{
			double d = ref_->findDepth( keypoints_curr_[i]);
			if ( d > 0)
			{
				Vector3d p_cam = ref_->camera_->pixel2camera(
					Vector2d( keypoints_curr_[i].pt.x, keypoints_curr_[i].pt.y ), d
				);
				pts_3d_ref_.push_back( cv::point3f( p_cam(0,0), p_cam(1,0), p_cam(2,0) ));
				descriptors_ref_.push_back( descriptors_curr_.row(i))
			}
		}
	}


	void VisualOdometry::poseEstimationPnP()
	{

	}











}