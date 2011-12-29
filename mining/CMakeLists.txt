project(WntrMiningPlugins)
cmake_minimum_required(VERSION 2.8)

include(WintermuteDefaults)
include(WintermuteMacros)

add_subdirectory(wintermute-plugin-mining)
add_subdirectory(nepomuk-wintermute)
add_subdirectory(zeitgeist-wintermute)
add_subdirectory(wikipedia-wintermute)
add_subdirectory(sysinfo-wintermute)

