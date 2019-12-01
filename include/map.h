#ifndef TYPINGSLAM_MAP_H
#define TYPINGSLAM_MAP_H

#include "common_include.h"
#include "mappoint.h"
#include "frame.h"

namespace typingslam{
	
	class Map{

	public:
		typedef shared_ptr<Map> Ptr;
		unordered_map<unsigned long, MapPoint::Ptr> map_points_;    // all landmarks, hash table to store them
		unordered_map<unsigned long, Frame::Ptr> keyframes_;    // all keyframes, hash table

		Map() {}

		void insertKeyFrame( Frame::Ptr frame );
		void insertMapPoint( MapPoint::Ptr map_point );


	};

}
#endif