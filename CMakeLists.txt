#1. 指定CMake版本
cmake_minimum_required(VERSION 3.2)
#2. 项目名称
PROJECT(test_slam)
#3. 头文件目录,相当于gcc中的-l方式
INCLUDE_DIRECTORIES(
        include
)
#4. 源文件目录
AUX_SOURCE_DIRECTORY(
        src src
)
#5.设置环境变量，编译用到的源文件全部都要放到这里，否则编译能够通过，但是执行的时候会出现各种问题，比如"symbol lookup error xxxxx , undefined symbol"
SET(TEST_MATH
        ${DIR_SRCS}
        )
#6.添加要编译的可执行文件
ADD_EXECUTABLE(${PROJECT_NAME} main.cpp)
#7.add link library，添加可执行文件所需要的库，比如我们用到了libm.so（命名规则：lib+name+.so），就添加该库的名称
#TARGET_LINK_LIBRARIES(${PROJECT_NAME} m)