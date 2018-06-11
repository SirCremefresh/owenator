cmake_minimum_required(VERSION 3.8)
project(owenator)

set(CMAKE_CXX_STANDARD 14)

add_executable(owenator main.cpp gui/gui.h gui/gui.cpp gui/button.h  list/list.h person/person.cpp person/person.h debt/debt.cpp debt/debt.h person/personNode.h debt/debtNode.h user/user.h user/user.cpp user/userNode.h)