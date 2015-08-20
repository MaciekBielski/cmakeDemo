include_directories(src)
add_library(server SHARED server1.c server2.c)
add_library(server_dev SHARED server1_dev.c server2_dev.c)
add_executable(client client.c)
add_executable(tester tester.c)
set_target_properties(server PROPERTIES
    LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib
    LIBRARY_OUTPUT_NAME server
    COMPILE_FLAGS "-g -Wall"
    VERSION 2.1
    SOVERSION 2
    POSITION_INDEPENDENT_CODE true
)
set_target_properties(server_dev PROPERTIES
    LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib/dev
    LIBRARY_OUTPUT_NAME server
    COMPILE_FLAGS "-g -Wall"
    VERSION 2.2
    SOVERSION 2
    POSITION_INDEPENDENT_CODE true
)
set(CLIENT_LINK_FLAGS "-L${CMAKE_SOURCE_DIR}/lib -lserver")
set_target_properties(client PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin
    RUNTIME_OUTPUT_NAME client
    LINK_FLAGS ${CLIENT_LINK_FLAGS}
)
set(TESTER_LINK_FLAGS "-L${CMAKE_SOURCE_DIR}/lib/dev -lserver")
set(TESTER_RPATH "-Wl,-rpath,${CMAKE_SOURCE_DIR}/lib/dev")
set_target_properties(tester PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin
    RUNTIME_OUTPUT_NAME tester
    LINK_FLAGS ${TESTER_LINK_FLAGS}
)
target_link_libraries(tester ${TESTER_RPATH})
add_dependencies(client server)
add_dependencies(tester server_dev)

