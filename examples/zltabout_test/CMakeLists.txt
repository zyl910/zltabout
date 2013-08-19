# zltabout_test: Test zltabout for C.
cmake_minimum_required(VERSION 2.6)
project(zltabout_test)
include_directories(${PROJECT_SOURCE_DIR}/../../src)
AUX_SOURCE_DIRECTORY(. SRC_LIST) 
SET(SRC_LIST ${SRC_LIST} ../../src/auto_tchar.h)
SET(SRC_LIST ${SRC_LIST} ../../src/auto_tmain.h)
SET(SRC_LIST ${SRC_LIST} ../../src/prichar.h)
SET(SRC_LIST ${SRC_LIST} ../../src/zltabout.h)
SET(SRC_LIST ${SRC_LIST} ../../src/zltabout_c.h)
SET(SRC_LIST ${SRC_LIST} ../../src/zltabout_c.c)
ADD_EXECUTABLE(zltabout_test ${SRC_LIST})

