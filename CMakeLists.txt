cmake_minimum_required(VERSION 3.25)
project(rpg)

set(CMAKE_CXX_STANDARD 17)

add_executable(rpg main.cpp weapon.h weapon.cpp armour.cpp item.cpp Person.cpp Person.h)
