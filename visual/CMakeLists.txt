project(WntrVisualPlugins)
cmake_minimum_required(VERSION 2.8)

include(WintermuteDefaults)
include(WintermuteMacros)

add_subdirectory(wintermute-plugin-frontend)
add_subdirectory(ncurses-wintermute)
add_subdirectory(gui-wintermute)
add_subdirectory(nlui-wintermute)

