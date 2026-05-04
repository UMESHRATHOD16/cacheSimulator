# Cache Simulator (C++)

A C++ implementation of a direct-mapped cache simulator to understand how memory access patterns affect performance.

## Overview

This project simulates how a CPU cache works using a direct-mapped strategy.  
It demonstrates how memory addresses are mapped to cache lines and how hit/miss decisions are made.

## Features

- Direct-mapped cache implementation
- Hit and miss detection
- Hit rate calculation
- Modular C++ design using header and source files

## How it works

For each memory access:
- Index is calculated using: `address % cache_size`
- If the cache line is valid and tag matches → **Hit**
- Otherwise → **Miss** and cache is updated

## Example


Access sequence:
1 -> Miss
2 -> Miss
3 -> Miss
1 -> Hit
4 -> Miss
5 -> Miss

Total Hits: 1
Hit Rate: 0.1667


## Project Structure


src/
├── main.cpp // runs simulation
├── cache.h // cache structure
├── cache.cpp // cache logic


## Build & Run


g++ src/main.cpp src/cache.cpp -o cache
./cache


## Learning Goals

- Understand cache memory behavior
- Learn modular C++ project structure
- Explore hit/miss patterns in memory systems