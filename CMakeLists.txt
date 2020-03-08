cmake_minimum_required(VERSION 3.10)
project(YellowBelt)

set(CMAKE_CXX_STANDARD 11)

add_executable(YellowBelt ThirdWeek/H_project/main.cpp ThirdWeek/H_project/query.cpp ThirdWeek/H_project/responses.cpp ThirdWeek/H_project/bus_manager.cpp)
