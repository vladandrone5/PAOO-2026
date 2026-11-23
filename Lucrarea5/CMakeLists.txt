cmake_minimum_required(VERSION 3.10)
project(Lucrarea5 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

add_executable(Lucrarea5
    src/main.cpp
    src/Widget.cpp
    src/Customer.cpp
    src/PriorityCustomer.cpp
)