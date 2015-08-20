1========================================
STRUCTURE

Each directory should have CMakeLists.txt, these from subdirs
inherits properties from parent dirs. Top CmakeLists.txt
must include:
cmake_minimum_required(VERSION 2.8)
CMAKE_SOURCE_DIR- top-level of CMakeLists.txt tree
CMAKE_BINARY_DIR- build directory

MAIN PROJECT NAME:
project(demo)

ADDING DIRECTORY TO CMAKELISTS.TXT TREE:
add_subdirectory(src)

ADDING DIRECTORY TO SOURCE FILES TREE:
include_directories(dirname)

2=======================================
FINDING SCRIPTS

/usr/share/cmake/Modules
find packages and libraries (like -I -l)
find_package(OpenCV REQUIRED)

3======================================
SETTING FLAGS

setting typical Makefile flags:
set(CMAKE_CXX_FLAG "-g -Wall")

4======================================
SETTING BIN AND BUILD DIRECTORIES

set_target_properties
(demo PROPERTIES RUNTIME_OUTPUT_DIRECTORY
                        ${CMAKE_SOURCE_DIR}/bin)
(demo PROPERTIES OUTPUT_NAME runDemo)
!!!
set_target_properties is powerful command

6======================================
MAKING A TARGET

building executable binary:
add_executable(demo src1.c src2.c)
add_library(demolib SHARED|STATIC|MODULE ...)

7=====================================
LINKING LIBRARIES

linking static libraries:
target_link_libraries(demo m) 

linking shared libraries:
set_target_properties+LINK_FLAGS

8=====================================
COMPILER PREPROCESSOR'S DEFINITIONS (-D) AND FLAGS

add_definitions(${CMAKE_CXX_FLAGS} "-std=c++11")

9====================================
FOREACH LOOP

set(PROGRAMS first second)
foreach(p ${PROGRAMS})
    set_target_properties(${p} ...)
endforeach(p)

use program name instead of project name, i.e:
add_executable(first first.cpp)
add_executable(second second.cpp ...)

10==================================
VIM + CMAKE

cmake is a wrapper around other build tool, i.e make; we
want to do out of source build, so, from inside build
directory (in project):
# cmake ..  //to point to top-level CMakeLists.txt

VIM_HACK(watch spaces):
vimrc.local inside top-level project directory:

let &makeprg="make -C build/release"
nmap <F9> :!cmake -DCMAKE_BUILD_TYPE=Release
                                -H. -Bbuild/release<CR>
nmap <F10> :silent make\|redraw!\|cc<CR>
nmap <F12> :!./bin/runDemo<CR>

cmake flags:
    -H<top_CMakeLists.txt_dir> -B<cmake_build_dst>

just open it `vim src` from top-level dir

11==================================
BUILDING A LIBRARY

add_library - adds a library target(detail in man)
can be STATIC|SHARED|MODE, for SHARED|MODE; 
-POSTION_INDEPENDENT_CODE target property is set;

connected:
-(ARCHIVE|LIBRARY|RUNTIME)_OUTPUT_DIRECTORY
change OUTPUT_NAME
-prefix and suffix are added automatically (default)
-set_target_properties(PROPERTIES:
    NAME, SONAME, VERSION,RPATH, LINK FLAGS, COMPILE_FLAGS)
-target_link_libraries
-find_package / find_library
-add_dependencies
-with static libraries you have to use 
  target_link_libraries()
-with shared libraries set_target_properties with
  LINK_FLAGS works well
-link_directories(<lib_dir>)
     where linker should look for libs

12==================================
RPATH AND CMAKE

rpath- runtime library search path, arguments passed to
runtime linker during compilation; to do it with cmake, use:

target_link_libraries()- sets rpath, pass to it:
-Wl,-rpath,<path_to_dev_libs>
