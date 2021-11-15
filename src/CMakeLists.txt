add_library( typingslam SHARED
    frame.cpp
    mappoint.cpp
    map.cpp
    camera.cpp
    config.cpp
    visual_odometry.cpp
    tracker.cc
)

target_link_libraries( typingslam
    ${THIRD_PARTY_LIBS}
)
