PROJECT(ex02)
CMAKE_MINIMUM_REQUIRED(VERSION 3.0)

INCLUDE_DIRECTORIES("${CMAKE_SOURCE_DIR}")

SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/../bin)

SET(src
	main.c
	)

ADD_EXECUTABLE(${PROJECT_NAME} ${src})
