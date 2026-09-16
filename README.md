# Digital Circuit Simulator

A lightweight digital circuit simulator built with **C++17, Qt6, and CMake** for modeling and simulating fundamental combinational digital circuits.

The project implements logic gates and combinational circuits as reusable C++ classes and uses **topological-order simulation** to propagate signals through connected components.

## Features

### Logic Gates

- AND
- OR
- NOT
- XOR
- NAND
- NOR
- XNOR

### Combinational Circuits

- Multiplexer (MUX)
- Demultiplexer (DEMUX)
- Half Adder
- Full Adder

### Circuit Simulation

- Binary input and output components
- Wire-based connections
- Multiple inputs and outputs
- Signal propagation between connected components
- Topological-order circuit evaluation
- Cycle detection for invalid combinational circuits

### Graphical Interface

The project includes a **Qt6-based GUI** with:

- Interactive binary input controls
- Circuit visualization
- Real-time output updates
- Full Adder visualization
- Simple and lightweight interface

## Architecture

The simulator represents a digital circuit as a directed graph.

- Gates are represented as nodes.
- Wires are represented as directed edges.
- Inputs and outputs are represented as circuit components.
- The `Circuit` class manages components and connections.
- Signals are propagated through wires during simulation.

```text
                 ┌─────────────┐
                 │    Input    │
                 └──────┬──────┘
                        │
                        ▼
                 ┌─────────────┐
                 │    Wire     │
                 └──────┬──────┘
                        │
                        ▼
                 ┌─────────────┐
                 │     Gate    │
                 │             │
                 │ AND / OR    │
                 │ XOR / NAND  │
                 │ NOR / XNOR  │
                 └──────┬──────┘
                        │
                        ▼
                 ┌─────────────┐
                 │   Output    │
                 └─────────────┘

```
## Simulation Algorithm

The simulator uses topological sorting to determine the order in which circuit components should be evaluated.

1. Calculate the indegree of every gate.
2. Find gates with indegree = 0.
3. Add them to a queue.
4. Evaluate the gate at the front of the queue.
5. Propagate its output through connected wires.
6. Decrease the indegree of destination gates.
7. Add newly available gates to the queue.
8. Continue until all gates are processed.
9. Report an error if a cycle prevents complete processing.

This approach allows combinational circuits to be simulated according to their dependency structure rather than a manually defined execution order.

## Supported Components
Basic Gates

| Gate | Operation           |
| ---- | ------------------- |
| AND  | Logical conjunction |
| OR   | Logical disjunction |
| NOT  | Logical inversion   |
| XOR  | Exclusive OR        |
| NAND | NOT of AND          |
| NOR  | NOT of OR           |
| XNOR | NOT of XOR          |

# MUX

The Multiplexer selects one of multiple inputs using a select signal.

Input 0 ──┐
          │
Input 1 ──┤──► MUX ──► Output
          │
Select ───┘

# Half Adder

A Half Adder accepts two binary inputs and produces:

SUM
CARRY

Logic:

SUM   = A XOR B
CARRY = A AND B

Example:

A = 1
B = 1

SUM   = 0
CARRY = 1

# Full Adder

A Full Adder accepts three inputs:

A
B
Carry In

and produces:

SUM
Carry Out

Example:

A       = 1
B       = 1
Carry In = 1

SUM       = 1
CARRY OUT = 1

because:

1 + 1 + 1 = 3 = 11₂
Object-Oriented Design

All major circuit components are built around the Gate base class.

                    Gate
                      │
       ┌──────────────┼──────────────┐
       │              │              │
    AND/OR          XOR/NAND       NOR/XNOR
       │
       ├── NOT
       ├── MUX
       ├── DEMUX
       ├── HalfAdder
       ├── FullAdder
       ├── Input
       └── Output

The use of inheritance and polymorphism allows different circuit components to implement their own evaluate() behavior while sharing a common interface.

## Project Structure
```text
DigitalCircuitSimulator/
│
├── CMakeLists.txt
├── README.md
├── .gitignore
│
├── include/
│   ├── Gate.h
│   ├── AndGate.h
│   ├── OrGate.h
│   ├── NotGate.h
│   ├── XorGate.h
│   ├── NandGate.h
│   ├── NorGate.h
│   ├── XnorGate.h
│   ├── Mux.h
│   ├── Demux.h
│   ├── HalfAdder.h
│   ├── FullAdder.h
│   ├── Input.h
│   ├── Output.h
│   ├── Wire.h
│   └── Circuit.h
│
└── src/
    ├── main.cpp
    ├── Gate.cpp
    ├── AndGate.cpp
    ├── OrGate.cpp
    ├── NotGate.cpp
    ├── XorGate.cpp
    ├── NandGate.cpp
    ├── NorGate.cpp
    ├── XnorGate.cpp
    ├── Mux.cpp
    ├── Demux.cpp
    ├── HalfAdder.cpp
    ├── FullAdder.cpp
    ├── Input.cpp
    ├── Output.cpp
    ├── Wire.cpp
    ├── Circuit.cpp
    ├── MainWindow.h
    └── MainWindow.cpp
```

## Technology Stack
C++17
Qt6 Widgets
CMake
C++ STL
Object-Oriented Programming
Graph Algorithms
Topological Sorting
Requirements
macOS
C++17-compatible compiler
CMake
Qt6

## Author

Krishna Verma

IIIT Allahabad

GitHub: https://github.com/krishnavermac
