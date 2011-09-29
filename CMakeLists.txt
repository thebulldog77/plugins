project(WntrPlugins)
cmake_minimum_required(VERSION 2.8)

include(WintermuteDefaults)
include(WintermuteMacros)

## TODO: Find a way to add WntrVoice (wintermute-plugin-voice) without clashing with a possibly
##       already installed copy of it.

add_subdirectory(pocketsphinx-wintermute)
add_subdirectory(marytts-wintermute)
