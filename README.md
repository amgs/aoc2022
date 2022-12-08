# Advent of Code 2022

## https://adventofcode.com/2022

## Usage

Any day $X, \forall X \in [1,25]$, generates two executables (one for each part), such as $dXpY, \forall Y \in [1,2]$.

```bash
cmake -S . -B build
cmake --build build
./build/dXpY
```

To build and run a specific part:

```bash
cmake --build build/ --target dXpY && ./build/dXpY 
```

## Dependencies

- C11
- CMake
