project(WntrVoiceSuite)
cmake_minimum_required(VERSION 2.8)

find_package(Wintermute 0.01 REQUIRED)

include(WintermuteDefaults)
include(WintermuteMacros)

add_subdirectory(wintermute-plugin-voice)

## Synthesizers
add_subdirectory(marytts-wintermute)
add_subdirectory(speechd-wintermute)

## Recognizers
add_subdirectory(pocketsphinx-wintermute)
