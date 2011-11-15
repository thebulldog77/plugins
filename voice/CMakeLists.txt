project(WntrVoicePlugins)
cmake_minimum_required(VERSION 2.8)

include(WintermuteDefaults)
include(WintermuteMacros)

add_subdirectory(wintermute-plugin-voice)

## Synthesizers
add_subdirectory(marytts-wintermute)
add_subdirectory(speechd-wintermute)

## Recognizers
## @todo Add support for Julius.
add_subdirectory(pocketsphinx-wintermute)
