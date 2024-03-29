cmake_minimum_required(VERSION 2.8 FATAL_ERROR)
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-deprecated-declarations")
set(CMAKE_BUILD_TYPE DEBUG)
#set(CMAKE_BUILD_TYPE RELEASE)

project(Tutorials)


# Check for c++11 support
INCLUDE(CheckCXXCompilerFlag)
CHECK_CXX_COMPILER_FLAG("-std=c++11" COMPILER_SUPPORTS_CXX11)
CHECK_CXX_COMPILER_FLAG("-std=c++0x" COMPILER_SUPPORTS_CXX0X)
IF(COMPILER_SUPPORTS_CXX11)
    SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pthread")
ELSEIF(COMPILER_SUPPORTS_CXX0X)
    SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x -pthread")
ELSE()
  MESSAGE(ERROR "The compiler ${CMAKE_CXX_COMPILER} has no C++11 support. Please use a different C++ compiler.")
ENDIF()



#C++ 14
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

#set warning level into errors 
if(MSVC)
  # Force to always compile with W4
  if(CMAKE_CXX_FLAGS MATCHES "/W[0-4]")
    string(REGEX REPLACE "/W[0-4]" "/W4" CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
  else()
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4")
  endif()
elseif(CMAKE_COMPILER_IS_GNUCC OR CMAKE_COMPILER_IS_GNUCXX)
  # Update if necessary
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wno-long-long -pedantic")
endif()

#Finding Memory leaking, Stack and Heap overflow
#set(CMAKE_CXX_FLAGS "-fsanitize=address ${CMAKE_CXX_FLAGS}")
#set(CMAKE_CXX_FLAGS "-fno-omit-frame-pointer ${CMAKE_CXX_FLAGS}")


######################### How to cpack create deb file#########################
 
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

ADD_EXECUTABLE(pointers  src/pointers.cpp )
TARGET_LINK_LIBRARIES( pointers)

ADD_EXECUTABLE(string  src/string.cpp )
TARGET_LINK_LIBRARIES( string)

ADD_EXECUTABLE(exception_handling  src/exception_handling.cpp)
TARGET_LINK_LIBRARIES( exception_handling)

ADD_EXECUTABLE(heap_vs_stackt  src/heap_vs_stackt.cpp)
TARGET_LINK_LIBRARIES(heap_vs_stackt)

ADD_EXECUTABLE(assert  src/assert.cpp)
TARGET_LINK_LIBRARIES(assert)

ADD_EXECUTABLE(return_abort_exit  src/return_abort_exit.cpp)
TARGET_LINK_LIBRARIES(return_abort_exit)

ADD_EXECUTABLE(rvalue_lvalue  src/rvalue_lvalue.cpp)
TARGET_LINK_LIBRARIES(rvalue_lvalue)

ADD_EXECUTABLE(primitive_data_types_numerical_limits_accuracy  src/primitive_data_types_numerical_limits_accuracy.cpp)
TARGET_LINK_LIBRARIES(primitive_data_types_numerical_limits_accuracy)

ADD_EXECUTABLE(arrays  src/arrays.cpp)
TARGET_LINK_LIBRARIES(arrays)


ADD_EXECUTABLE(data_type_info  src/data_type_info.cpp)
TARGET_LINK_LIBRARIES(data_type_info)

ADD_EXECUTABLE(dynamic_memory_allocation src/dynamic_memory_allocation.cpp)
TARGET_LINK_LIBRARIES(dynamic_memory_allocation)

#ADD_LIBRARY(add MODULE src/add.cpp)
ADD_EXECUTABLE(loadeding_libraries src/loadeding_libraries.cpp )
TARGET_LINK_LIBRARIES(loadeding_libraries dl)

ADD_EXECUTABLE(template src/template.cpp )
TARGET_LINK_LIBRARIES(template)

ADD_DEFINITIONS(-DLOGING=0)
ADD_EXECUTABLE(macro src/macro.cpp)
TARGET_LINK_LIBRARIES(macro)

ADD_EXECUTABLE(inline_functions src/inline_functions.cpp)
TARGET_LINK_LIBRARIES(inline_functions)

ADD_EXECUTABLE(align src/align.cpp)
TARGET_LINK_LIBRARIES(align)

ADD_EXECUTABLE(non_modifing_algorithm src/non_modifing_algorithm.cpp)
TARGET_LINK_LIBRARIES(non_modifing_algorithm)

ADD_EXECUTABLE(vector src/vector.cpp)
TARGET_LINK_LIBRARIES(vector)

ADD_EXECUTABLE(variadic_templates src/variadic_templates.cpp)
TARGET_LINK_LIBRARIES(variadic_templates)

ADD_EXECUTABLE(enum src/enum.cpp)
TARGET_LINK_LIBRARIES(enum)

ADD_EXECUTABLE(diamond_problem_virtual_inheritance src/class/diamond_problem_virtual_inheritance.cpp)
TARGET_LINK_LIBRARIES(diamond_problem_virtual_inheritance)

ADD_EXECUTABLE(shadowing src/class/shadowing.cpp)
TARGET_LINK_LIBRARIES(shadowing)

ADD_EXECUTABLE(protected_friend_class_function src/class/protected_friend_class_function.cpp)
TARGET_LINK_LIBRARIES(protected_friend_class_function)

ADD_EXECUTABLE(virtual_function_abstract_class src/class/virtual_function_abstract_class.cpp)
TARGET_LINK_LIBRARIES(virtual_function_abstract_class)

ADD_EXECUTABLE(multiple_inheritance_polymorphism src/class/multiple_inheritance_polymorphism.cpp)
TARGET_LINK_LIBRARIES(multiple_inheritance_polymorphism)

ADD_EXECUTABLE(private_public_protected_inheritance src/class/private_public_protected_inheritance.cpp)
TARGET_LINK_LIBRARIES(private_public_protected_inheritance)

ADD_EXECUTABLE(cast_Base_to_Derived_to_Base src/class/cast_Base_to_Derived_to_Base.cpp)
TARGET_LINK_LIBRARIES(cast_Base_to_Derived_to_Base)

ADD_EXECUTABLE(operator_overloading  src/class/operator_overloading.cpp )
TARGET_LINK_LIBRARIES( operator_overloading)

ADD_EXECUTABLE(default_0_delete_meaning  src/class/default_0_delete_meaning.cpp)
TARGET_LINK_LIBRARIES(default_0_delete_meaning)

ADD_EXECUTABLE(circular_dependency
    src/class/Circular_Dependency/circular_dependency.cpp
    src/class/Circular_Dependency/a.cpp
    src/class/Circular_Dependency/b.cpp
    src/class/Circular_Dependency/c.cpp)
TARGET_LINK_LIBRARIES(circular_dependency)

ADD_EXECUTABLE(switch_case src/switch_case.cpp)
TARGET_LINK_LIBRARIES(switch_case)

ADD_EXECUTABLE(set_map_pair_tuple src/set_map_pair_tuple.cpp)
TARGET_LINK_LIBRARIES(set_map_pair_tuple)

ADD_EXECUTABLE(cast_RTTI src/cast_RTTI.cpp)
TARGET_LINK_LIBRARIES(cast_RTTI)

ADD_EXECUTABLE(signals src/signals.cpp)
TARGET_LINK_LIBRARIES(signals)

ADD_EXECUTABLE(error_handling src/error_handling.cpp)
TARGET_LINK_LIBRARIES(error_handling)

ADD_EXECUTABLE(bitwise_operations src/bitwise_operations.cpp)
TARGET_LINK_LIBRARIES(bitwise_operations)

ADD_EXECUTABLE(bitset src/bitset.cpp)
TARGET_LINK_LIBRARIES(bitset)

ADD_EXECUTABLE(multithreading src/multithreading.cpp)
TARGET_LINK_LIBRARIES(multithreading)

ADD_EXECUTABLE(function_pointer src/function_pointer.cpp)
TARGET_LINK_LIBRARIES(function_pointer)

ADD_EXECUTABLE(bind src/bind.cpp)
TARGET_LINK_LIBRARIES(bind)

ADD_EXECUTABLE(function src/function.cpp)
TARGET_LINK_LIBRARIES(function)

ADD_EXECUTABLE(lambda src/lambda.cpp)
TARGET_LINK_LIBRARIES(lambda)

ADD_EXECUTABLE(unions src/unions.cpp)
TARGET_LINK_LIBRARIES(unions)

ADD_EXECUTABLE(timers src/timers.cpp)
TARGET_LINK_LIBRARIES(timers)

ADD_EXECUTABLE(fork src/fork.cpp)
TARGET_LINK_LIBRARIES(fork)

ADD_EXECUTABLE(streams_IO_operation_format_output src/streams_IO_operation_format_output.cpp)
TARGET_LINK_LIBRARIES(streams_IO_operation_format_output)

ADD_EXECUTABLE(explicit  src/explicit.cpp)
TARGET_LINK_LIBRARIES(explicit)

ADD_EXECUTABLE(volatile  src/volatile.cpp)
TARGET_LINK_LIBRARIES(volatile)

ADD_EXECUTABLE(register  src/register.cpp)
TARGET_LINK_LIBRARIES(register)

ADD_EXECUTABLE(const_constexpr_mutable  src/const_constexpr_mutable.cpp)
TARGET_LINK_LIBRARIES(const_constexpr_mutable)

ADD_EXECUTABLE(literals  src/literals.cpp)
TARGET_LINK_LIBRARIES(literals)

ADD_EXECUTABLE(ternary src/ternary.cpp)
TARGET_LINK_LIBRARIES(ternary)

ADD_EXECUTABLE(lists src/lists.cpp)
TARGET_LINK_LIBRARIES(lists)

ADD_EXECUTABLE(type_traits src/type_traits.cpp)
TARGET_LINK_LIBRARIES(type_traits)

ADD_EXECUTABLE(pimpl src/pimpl/main.cpp src/pimpl/studentpimpl.cpp)
TARGET_LINK_LIBRARIES(pimpl)

ADD_EXECUTABLE(abstract_class_vs_interface src/class/abstract_class_vs_interface.cpp)
TARGET_LINK_LIBRARIES(abstract_class_vs_interface)

ADD_EXECUTABLE(typedef src/typedef.cpp)
TARGET_LINK_LIBRARIES(typedef)

ADD_EXECUTABLE(most_vexing_parse src/most_vexing_parse.cpp)
TARGET_LINK_LIBRARIES(most_vexing_parse)

ADD_EXECUTABLE(VTABLE_and_VPTR src/VTABLE_and_VPTR.cpp)
TARGET_LINK_LIBRARIES(VTABLE_and_VPTR)


OPTION(TESTING "Enable testing" OFF)
IF(testing_enabled)
	ADD_SUBDIRECTORY(tests)
ENDIF()

IF(IS_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/src/temp")
	ADD_SUBDIRECTORY(src/temp)
ENDIF()

IF(IS_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/src/hackerrank")
	ADD_SUBDIRECTORY(src/hackerrank)
ENDIF()



