## @todo Have this file build all of the projects in the subdirectories.
cmake_minimum_required(VERSION 2.8)
project(WntrPlugins)
set(WNTRPLUGINS_DIR "sample" CACHE STRING "Lists the names of the plugin directories to be built and installed.")
add_subdirectory(${WNTRPLUGINS_DIR})
