# project name
PROJECT(RBGrange) #基本上用工作空间或者包命名
# requirement of cmake version
cmake_minimum_required(VERSION 3.5) #cmake的版本

find_package(OpenCV REQUIRED) #搜索OpenCV
# directory of opencv headers
include_directories(${OpenCV_INCLUDE_DIRS}) #编译时加到包含目录

add_executable(RGBrange main.cpp) #生成可执行文件  add_executable({可执行文件名} {需要编译的cpp文件位置}) 
# directory of opencv library
link_directories(${OpenCV_LIBRARY_DIRS})

target_link_libraries(RGBrange ${OpenCV_LIBRARIES})
                    
