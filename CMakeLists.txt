cmake_minimum_required(VERSION 3.10)

project(par_sort)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(OpenCV REQUIRED)
find_package(Boost REQUIRED COMPONENTS system)
message(STATUS "Taskflow include path: ${CMAKE_SOURCE_DIR}/taskflow")

add_executable(par_sort
    src/main.cpp
    src/config.cpp
    src/motion_detector.cpp
    src/notifier.cpp
    src/thread_manager.cpp
)

target_include_directories(par_sort PRIVATE ${OpenCV_INCLUDE_DIRS} ${CMAKE_SOURCE_DIR}/taskflow ${Boost_INCLUDE_DIRS})
target_link_libraries(par_sort PRIVATE ${OpenCV_LIBS} Boost::system)
