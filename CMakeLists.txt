cmake_minimum_required(VERSION 3.16)

project(DigitalCircuitSimulator)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets)

add_executable(DigitalCircuitSimulator

    src/main.cpp

    src/MainWindow.h
    src/MainWindow.cpp

    src/Gate.cpp

    src/AndGate.cpp
    src/OrGate.cpp
    src/NotGate.cpp
    src/XorGate.cpp
    src/NandGate.cpp
    src/NorGate.cpp
    src/XnorGate.cpp

    src/Mux.cpp
    src/Demux.cpp

    src/HalfAdder.cpp
    src/FullAdder.cpp

    src/Input.cpp
    src/Output.cpp

    src/Wire.cpp
    src/Circuit.cpp
)

target_include_directories(DigitalCircuitSimulator
    PRIVATE
    include
    src
)

target_link_libraries(DigitalCircuitSimulator
    PRIVATE
    Qt6::Widgets
)