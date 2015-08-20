include_directories(src)
# anyhow compilation happens together
add_executable(students group.cpp student.cpp main.cpp)
add_executable(hello secondHello.cpp)
target_link_libraries(students m)
add_definitions(${CMAKE_CXX_FLAGS} "-std=c++11")
