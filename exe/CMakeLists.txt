cmake_minimum_required(VERSION 2.6)
project(exeDemo)

# scripts for finding external libraries can be here
# instead of setting standard flags -I -l...
# find_package()
message("Build type: id ${CMAKE_BUILD_TYPE}")
add_subdirectory(src)
set_target_properties(exeDemo PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)
set_target_properties(exeDemo PROPERTIES OUTPUT_NAME exeDemo)
