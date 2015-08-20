cmake_minimum_required(VERSION 2.8)
project(sharedLib)

add_subdirectory(src)
set(PROGRAMS client server server_dev tester)
