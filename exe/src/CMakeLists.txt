include_directories(src)
# anyhow compilation happens together
add_executable(exeDemo group.cpp student.cpp main.cpp)
add_definitions(${CMAKE_CXX_FLAGS} "-std=c++11")
target_link_libraries(exeDemo m)
