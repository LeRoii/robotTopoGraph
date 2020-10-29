cmake_minimum_required(VERSION 3.0)

project(xmleg VERSION 1.00)

find_package( OpenCV 4 REQUIRED )

message(STATUS "OpenCV版本: ${OpenCV_VERSION}")
message(STATUS "    头文件目录：${OpenCV_INCLUDE_DIRS}")
message(STATUS "    库文件目录：${OpenCV_LIB_DIR}")
message(STATUS "    库文件列表：${OpenCV_LIBS}")


INCLUDE_DIRECTORIES(thirdparty/)

# set(HEADERS ../src/pugixml.hpp ../src/pugiconfig.hpp)
set(SOURCES  thirdparty/pugixml.cpp
             testgraph.cpp 
             robottoponode.cpp
             robottopograph.cpp)

add_executable(xmleg ${SOURCES})
target_link_libraries(xmleg ${OpenCV_LIBS})

add_executable(traverse thirdparty/pugixml.cpp
                        traverse_base.cpp )