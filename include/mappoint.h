namespace typingslame{
    class MapPoint
    {
    public:
        typedef shared_ptr<MapPoint> Ptr;
        unsigned long id_;              //ID
        Vector3d pos_;                  //position in the world
        Vector3d norm_;                 //Normal of veiwing direction
        Mat descriptor_;                //Descriptor for matching
        int observed_times_;            // being observed by feature matching algo
        int correct_times_;             //being an inliner in pose estimation
        
        MapPoint();
        MapPoint( long id, Vector3d position, Vector3d norm );
        
        // factory function
        static MapPoint::Ptr createMapPoint();
    };
}