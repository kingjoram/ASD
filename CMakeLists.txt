cmake_minimum_required(VERSION 3.26)


project(HW1)


add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/googletest" "googletest")


add_executable(Tests tests/TestList.cpp 
		     src/List_graph.cpp
		     src/Arc_graph.cpp
		     src/Matrix_graph.cpp 
		     src/Set_graph.cpp)


target_include_directories(
	Tests PRIVATE 
	"${CMAKE_CURRENT_SOURCE_DIR}/include"
)

target_link_libraries(
	Tests PRIVATE
	gtest gtest_main
)
