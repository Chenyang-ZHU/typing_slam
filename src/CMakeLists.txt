add_library( typingslam SHARED
    frame.cpp
    mappoint.cpp
    map.cpp
    camera.cpp
    config.cpp
)

target_link_libraries( typingslam
    ${THIRD_PARTY_LIBS}
)
