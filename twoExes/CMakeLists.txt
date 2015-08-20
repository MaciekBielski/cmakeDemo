cmake_minimum_required(VERSION 2.6)
project(twoExes)

# scripts for finding external libraries can be here
# instead of setting standard flags -I -l...
# find_package()
add_subdirectory(src)
set(PROGRAMS students hello)
foreach(prog ${PROGRAMS})
    set_target_properties(${prog} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)
    set_target_properties(${prog} PROPERTIES OUTPUT_NAME ${prog})
endforeach(prog)
