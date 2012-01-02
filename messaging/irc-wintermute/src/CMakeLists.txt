cmake_minimum_required(VERSION 2.8)

file(GLOB IRCWNTR_CPP "*.cpp")
file(GLOB IRCWNTR_HPP "*.hpp")

QT4_WRAP_CPP(IRCWNTR_CPP ${IRCWNTR_HPP})

add_library(irc-wintermute ${IRCWNTR_CPP})
