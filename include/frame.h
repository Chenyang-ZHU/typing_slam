namespace typingslam{
    class Frame
    {
        typedef std::shared_ptr<Frame> Ptr;
        unsigned long id_;  // id of this frame
        double time_stamp; // when its is recored
        SE3 T_c_w_;        // transform from world to camera
        Camera::Ptr camera_;  // Pinhole RGB-D camera model
        Mat color_, depth_;   // color and depth image
    
    // data member
    public:
        Frame();
        Frame(long id, double time_stamp=0, SE3 T_c_w=SE3(), Camera::Ptr camera=nullptr,Mat color = Mat(), Mat depth = Mat());
        ~Frame();
        
        // factory function
        static Frame::Ptr createFrame();
        
        // find the depth in depth map
        double findDepth( const cv::KeyPoint& kp );
        
        //get camera center
        Vector3d getCamCenter() const;
        
        //check if a point is in the frame
        bool isInFrame( const Vector& pt_world);
        
    };
}