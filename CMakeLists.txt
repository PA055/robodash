cmake_minimum_required(VERSION 3.10)
include(FetchContent)

project(robodash-sim)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 20)

add_compile_definitions(SIMULATOR)

file(
	GLOB_RECURSE SOURCES CONFIGURE_DEPENDS
	"${CMAKE_CURRENT_SOURCE_DIR}/simulator/**/*.cpp"
	"${CMAKE_CURRENT_SOURCE_DIR}/src/**/*.cpp"
	"${CMAKE_CURRENT_SOURCE_DIR}/src/**/*.c"
)

add_executable(robodash-sim "${SOURCES}")

set(LV_CONF_PATH "${CMAKE_CURRENT_SOURCE_DIR}/simulator/lv_conf.h" CACHE STRING "" FORCE)

# Local includes
target_include_directories(robodash-sim PRIVATE include)
target_include_directories(robodash-sim PRIVATE simulator)

# SDL2
find_package(SDL2 REQUIRED SDL2)
target_link_libraries(robodash-sim PRIVATE SDL2::SDL2)

# LVGL
FetchContent_Declare(
	lvgl
	GIT_REPOSITORY https://github.com/lvgl/lvgl.git
	GIT_TAG v8.3.11
)
FetchContent_MakeAvailable(lvgl)

target_link_libraries(robodash-sim PRIVATE lvgl::lvgl)

# FIXME: this brokey idk why
# FetchContent_Declare(
# lv_drivers
# GIT_REPOSITORY https://github.com/lvgl/lv_drivers.git
# )
# FetchContent_MakeAvailable(lv_drivers)

# target_link_libraries(robodash-sim PRIVATE lvgl::drivers)
