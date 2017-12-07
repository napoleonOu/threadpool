CMAKE_MINIMUM_REQUIRED(VERSION 2.8)
project(threadpool)
set(CMAKE_MAKE_PROGRAM d:/msys64/mingw64/bin/mingw32-make.exe)
set(CMAKE_C_COMPILER d:/msys64/mingw64/bin/gcc.exe)
set(CMAKE_CXX_COMPILER d:/msys64/mingw64/bin/g++.exe)
set(CMAKE_CXX_STANDARD 11)
set(project_HEADERS syncqueue.h )
set(project_SOURCES main.cpp) 
ADD_EXECUTABLE(threadpool ${project_HEADERS}
			  ${project_SOURCES})

