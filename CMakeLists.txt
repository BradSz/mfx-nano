cmake_minimum_required(VERSION 3.10.0)
project(multi-fx VERSION 0.1.0)

include(CTest)
enable_testing()

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

#set(CMAKE_CXX_FLAGS "-std=c++11 -Wall -Wpedantic -Weffc++")
set(CMAKE_CXX_FLAGS "-Wall -Wpedantic -Weffc++")
#set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
#set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
#set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

find_program(CCACHE_FOUND ccache)
if(CCACHE_FOUND)
    set_property(GLOBAL PROPERTY RULE_LAUNCH_COMPILE ccache)
    set_property(GLOBAL PROPERTY RULE_LAUNCH_LINK ccache) # Less useful to do it for linking, see edit2
endif(CCACHE_FOUND)

# Find external libraries
find_package(Boost 1.65 COMPONENTS program_options thread system chrono log REQUIRED)

# Source root
include_directories(src)

# All source files
file(GLOB_RECURSE all_srcs RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} src/*.h src/*.cpp)
list(REMOVE_ITEM all_srcs src/main.cpp)

# Library source files
set(lib_srcs ${all_srcs})
list(FILTER lib_srcs EXCLUDE REGEX ".*Test.cpp$")
add_library(mfx ${lib_srcs})

# Test source files
set(test_srcs ${all_srcs})
list(FILTER test_srcs INCLUDE REGEX ".*Test.cpp$")
set(test_name unittest)
add_executable(${test_name} ${test_srcs})
target_link_libraries(${test_name} mfx ${Boost_LIBRARIES})
add_test(
  NAME              ${test_name}
  WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/bin
  COMMAND           ${CMAKE_BINARY_DIR}/bin/${test_name}
)

# Executable
add_executable(multi-fx src/main.cpp)
target_link_libraries(multi-fx mfx ${Boost_LIBRARIES})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

