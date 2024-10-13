cmake_minimum_required(VERSION 3.29)
project(Graphic_Clock)

set(CMAKE_CXX_STANDARD 20)

add_executable(Graphic_Clock main.cpp
        Counter.cpp
        Counter.h
        ClockController.cpp
        ClockController.h
        CounterView.cpp
        CounterView.h
        ClockView.cpp
        ClockView.h
        ClockModel.cpp
        ClockModel.h
        KeyControls.h
        Clock.h
        Clock.cpp)

target_link_libraries(Graphic_Clock sfml-graphics sfml-audio)

find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)
