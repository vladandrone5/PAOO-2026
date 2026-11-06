cmake_minimum_required(VERSION 3.10)
project(EffectiveCpp_PAOO)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(include)

add_executable(EffectiveCpp_PAOO 
    src/main.cpp 
    src/Item4.cpp
)