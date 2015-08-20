include_directories(src)
add_library(server STATIC server1.c server2.c)
add_executable(client client.c)
add_definitions(${CMAKE_C_FLAGS} "-g -Wall")
set_target_properties(server PROPERTIES 
        ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib
        ARCHIVE_OUTPUT_NAME server
        )
set(CLIENT_LINK_FLAGS "-Wl,-Bstatic -L${CMAKE_SOURCE_DIR}/lib -lserver -Wl,-Bdynamic") 
set_target_properties(client PROPERTIES 
        RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin
        RUNTIME_OUTPUT_NAME client
        )
target_link_libraries(client ${CLIENT_LINK_FLAGS})
add_dependencies(client server)
