cmake_minimum_required(VERSION 3.24)

project(scout-engine)

add_subdirectory("deps/glfw" "deps/glfw/build")
add_subdirectory("deps/glm" "deps/glm/build")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED On)

add_executable(scoutengine
	"src/glad.c"
	"src/main.cpp"
)

target_include_directories(scoutengine PUBLIC "include/")
target_include_directories(scoutengine PUBLIC "deps/glfw/include/")
target_include_directories(scoutengine PUBLIC "deps/glm/glm/")

target_link_libraries(scoutengine glfw)
target_link_libraries(scoutengine glm)
