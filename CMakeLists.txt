cmake_minimum_required(VERSION 3.5.0)
project(ccwc VERSION 0.1.0 LANGUAGES C CXX)

file(GLOB CCWC_SRC CONFIGURE_DEPENDS "src/*.h" "src/*.cpp")

add_executable(ccwc ${CCWC_SRC})

include(CTest)
enable_testing()

