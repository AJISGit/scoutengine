cmake_minimum_required(VERSION 3.24)

project(scoutengine VERSION 0.1 LANGUAGES C CXX)


add_subdirectory(deps/glfw deps/glfw/build)
add_subdirectory(deps/glm deps/glm/build)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED On)

add_library(

	scout STATIC
	
	include/KHR/khrplatform.h
	include/glad/glad.h


	include/scout.hpp
	include/platformtype.hpp

	src/glad.c
)

target_include_directories(scout PUBLIC "include")

target_link_libraries(scout glfw)
target_link_libraries(scout glm)

add_executable(

	scoutengine

	src/main.cpp

)


target_include_directories(scoutengine PUBLIC include)

target_link_libraries(scoutengine scout)
target_link_libraries(scoutengine glfw)
target_link_libraries(scoutengine glm)
