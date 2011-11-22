project(WntrMessagingPlugins)
cmake_minimum_required(VERSION 2.8)

include(WintermuteDefaults)
include(WintermuteMacros)

add_subdirectory(wintermute-plugin-messaging)
add_subdirectory(xmpp-wintermute)
add_subdirectory(irc-wintermute)
