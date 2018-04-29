cmake_minimum_required(VERSION 2.8 FATAL_ERROR)
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-deprecated-declarations")
set(CMAKE_BUILD_TYPE Debug)

project(Tutorials)
#set(CMAKE_BUILD_TYPE Debug)



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




INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/src/)

#ADD_EXECUTABLE(lmcma src/lmcma.cpp)
#TARGET_LINK_LIBRARIES(lmcma)
#add_library(add SHARED src/add.cpp)

#ADD_EXECUTABLE(DynamicallyLoadedLibraries src/DynamicallyLoadedLibraries.cpp  )
#TARGET_LINK_LIBRARIES(DynamicallyLoadedLibraries dl )



#ADD_EXECUTABLE(Sandbox src/Sandbox.cpp)
#TARGET_LINK_LIBRARIES(Sandbox)

#ADD_EXECUTABLE(Constructor_InitializationList src/Constructor_InitializationList.cpp)
#TARGET_LINK_LIBRARIES(Constructor_InitializationList)



ADD_EXECUTABLE(Temp src/Temp.cpp)
TARGET_LINK_LIBRARIES(Temp)

#ADD_EXECUTABLE(Map_custom_type src/Container/Map_custom_type.cpp)
#TARGET_LINK_LIBRARIES(Map_custom_type)

ADD_EXECUTABLE(VectorsExample src/Container/VectorsExample.cpp)
TARGET_LINK_LIBRARIES(VectorsExample)


ADD_EXECUTABLE(assert src/assert.cpp)
TARGET_LINK_LIBRARIES(assert)



#ADD_EXECUTABLE(Sandbox src/Sandbox.cpp)
#TARGET_LINK_LIBRARIES(Sandbox)




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
#ADD_EXECUTABLE(yaml-cpp_test src/yaml-cpp_test.cpp)
#TARGET_LINK_LIBRARIES(yaml-cpp_test yaml-cpp)


#ADD_EXECUTABLE(argv_argc_debugg src/argv_argc_debugg.cpp)
#TARGET_LINK_LIBRARIES(argv_argc_debugg)


#ADD_EXECUTABLE(csv_test src/csv_test.cpp src/csv.h)
#TARGET_LINK_LIBRARIES(csv_test)


#ADD_EXECUTABLE(template_specialization src/template_specialization.cpp)
#TARGET_LINK_LIBRARIES(template_specialization)


#ADD_EXECUTABLE(dynamic_programming src/dynamic_programming.cpp)
#TARGET_LINK_LIBRARIES(dynamic_programming)


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


ADD_EXECUTABLE(VectorConversiontoArray src/Container/VectorConversiontoArray.cpp)
TARGET_LINK_LIBRARIES(VectorConversiontoArray)


ADD_EXECUTABLE(Multithreading src/Multithreading.cpp)
TARGET_LINK_LIBRARIES(Multithreading pthread)


ADD_EXECUTABLE(non-modifing-algorithm src/non-modifing-algorithm.cpp)
TARGET_LINK_LIBRARIES(non-modifing-algorithm)

ADD_EXECUTABLE(Multithreading_c11 src/Multithreading_c11.cpp)
TARGET_LINK_LIBRARIES(Multithreading_c11 pthread)


ADD_EXECUTABLE(sort_algorithms src/sort_algorithms.cpp)
TARGET_LINK_LIBRARIES(sort_algorithms)

ADD_EXECUTABLE(types_and_variables src/types_and_variables.cpp)
TARGET_LINK_LIBRARIES(types_and_variables)


ADD_EXECUTABLE(streams src/streams.cpp)
TARGET_LINK_LIBRARIES(streams)


ADD_EXECUTABLE(hash_table src/hash_table.cpp)
TARGET_LINK_LIBRARIES(hash_table)


ADD_EXECUTABLE(heap_stack src/heap_stack.cpp)
TARGET_LINK_LIBRARIES(heap_stack)




ADD_EXECUTABLE(heap src/heap.cpp)
TARGET_LINK_LIBRARIES(heap)

