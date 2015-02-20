cmake_minimum_required(VERSION 2.8 FATAL_ERROR)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-deprecated-declarations")
set(CMAKE_BUILD_TYPE Debug)

project(Tutorials)
set(CMAKE_BUILD_TYPE Debug)


if(NOT DEFINED PROCESSOR_COUNT)
  # Unknown:
  set(PROCESSOR_COUNT 0)
 
  # Linux:
  set(cpuinfo_file "/proc/cpuinfo")
  if(EXISTS "${cpuinfo_file}")
    file(STRINGS "${cpuinfo_file}" procs REGEX "^processor.: [0-9]+$")
    list(LENGTH procs PROCESSOR_COUNT)
  endif()
 
  # Mac:
  if(APPLE)
    find_program(cmd_sys_pro "system_profiler")
    if(cmd_sys_pro)
      execute_process(COMMAND ${cmd_sys_pro} OUTPUT_VARIABLE info)
      string(REGEX REPLACE "^.*Total Number Of Cores: ([0-9]+).*$" "\\1"
        PROCESSOR_COUNT "${info}")
    endif()
  endif()
 
  # Windows:
  if(WIN32)
    set(PROCESSOR_COUNT "$ENV{NUMBER_OF_PROCESSORS}")
  endif()
endif()

MESSAGE("Number of Cores: " ${PROCESSOR_COUNT} )
INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/src/)

#ADD_EXECUTABLE(lmcma src/lmcma.cpp)
#TARGET_LINK_LIBRARIES(lmcma)
#add_library(add SHARED src/add.cpp)

#ADD_EXECUTABLE(DynamicallyLoadedLibraries src/DynamicallyLoadedLibraries.cpp  )
#TARGET_LINK_LIBRARIES(DynamicallyLoadedLibraries dl )



ADD_EXECUTABLE(Sandbox src/Sandbox.cpp)
TARGET_LINK_LIBRARIES(Sandbox)


ADD_EXECUTABLE(Map_custom_type src/Container/Map_custom_type.cpp)
TARGET_LINK_LIBRARIES(Map_custom_type)

ADD_EXECUTABLE(Map src/Container/Map.cpp)
TARGET_LINK_LIBRARIES(Map)

