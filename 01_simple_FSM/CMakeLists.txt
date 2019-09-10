cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

project(01_simple_FSM LANGUAGES C)

include_directories(inc/)

add_library(keyboard STATIC
	src/keyboard.c
)

add_executable(${PROJECT_NAME} src/main.c)

target_link_libraries(${PROJECT_NAME} keyboard)
