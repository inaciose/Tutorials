cmake_minimum_required(VERSION 2.8 FATAL_ERROR)
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-deprecated-declarations")
set(CMAKE_BUILD_TYPE Debug)

project(Tutorials)


# Check for c++11 support
INCLUDE(CheckCXXCompilerFlag)
CHECK_CXX_COMPILER_FLAG("-std=c++11" COMPILER_SUPPORTS_CXX11)
CHECK_CXX_COMPILER_FLAG("-std=c++0x" COMPILER_SUPPORTS_CXX0X)
IF(COMPILER_SUPPORTS_CXX11)
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
ELSEIF(COMPILER_SUPPORTS_CXX0X)
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")
ELSE()
  MESSAGE(ERROR "The compiler ${CMAKE_CXX_COMPILER} has no C++11 support. Please use a different C++ compiler.")
ENDIF()

set(CMAKE_CXX_FLAGS "-std=c++0x ${CMAKE_CXX_FLAGS}")


#C++ 14
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)


#Finding Memory leaking, Stack and Heap overflow
set(CMAKE_CXX_FLAGS "-fsanitize=address ${CMAKE_CXX_FLAGS}")
set(CMAKE_CXX_FLAGS "-fno-omit-frame-pointer ${CMAKE_CXX_FLAGS}")


######################### How to cpack create deb file#########################

#FIND_PACKAGE(VTK REQUIRED)
#INCLUDE(${VTK_USE_FILE})
 
#ADD_EXECUTABLE(DistanceBetweenPoints src/DistanceBetweenPoints.cpp)
#INSTALL(TARGETS DistanceBetweenPoints DESTINATION distance)
 
#SET(CPACK_GENERATOR "DEB")
#SET(CPACK_DEBIAN_PACKAGE_MAINTAINER "David Doria") #required
 
#INCLUDE(CPack)
 
# To use this:
# make package
# sudo dpkg -i DistanceBetweenPoints-0.1.1-Linux.deb
 
# This will result in the file:
#/usr/distance/DistanceBetweenPoints


# To use this:
# make package
# sudo dpkg -i DistanceBetweenPoints-0.1.1-Linux.deb
 
# This will result in the file:
#/usr/distance/DistanceBetweenPoints

#https://cmake.org/Wiki/CMake:Packaging_With_CPack

##############################################################################################


#set(Ceres_DIR  "$ENV{HOME}/usr/lib/cmake/Ceres")
#find_package (Ceres REQUIRED)
#MESSAGE("Ceres_VERSION: " ${Ceres_VERSION})
#MESSAGE("CERES_INCLUDE_DIRS: " ${CERES_INCLUDE_DIRS})
#MESSAGE("CERES_LIBRARIES: " ${CERES_LIBRARIES})


#set(gflags_DIR "$ENV{HOME}/usr/lib/cmake/gflags/")

#find_package(gflags REQUIRED)
##find_package(gflags COMPONENTS nothreads_static)
#MESSAGE("GFLAGS_FOUND: " ${GFLAGS_FOUND})
#MESSAGE("GFLAGS_INCLUDE_DIRS: " ${GFLAGS_INCLUDE_DIRS})
#MESSAGE("GFLAGS_LIBRARIES: " ${GFLAGS_LIBRARIES})
#MESSAGE("GFLAGS_LIBRARYRARY_DIRS: " ${GFLAGS_LIBRARYRARY_DIRS} )
#add_definitions(-DCERES_GFLAGS_NAMESPACE=${GFLAGS_NAMESPACE})


#ADD_EXECUTABLE(glog_example src/glog_example.cpp)
#TARGET_LINK_LIBRARIES(glog_example ${GFLAGS_LIBRARIES} ${CERES_LIBRARIES} gflags)




ADD_EXECUTABLE(string  src/string.cpp )
TARGET_LINK_LIBRARIES( string)

ADD_EXECUTABLE(overloading  src/overloading.cpp )
TARGET_LINK_LIBRARIES( overloading)



