# Well with wheel

[![Windows build](https://github.com/JMazurkiewicz/GKOM-well-with-wheel/actions/workflows/windows.yaml/badge.svg)](https://github.com/JMazurkiewicz/GKOM-well-with-wheel/actions/workflows/windows.yaml)
[![Linux build](https://github.com/JMazurkiewicz/GKOM-well-with-wheel/actions/workflows/linux.yaml/badge.svg)](https://github.com/JMazurkiewicz/GKOM-well-with-wheel/actions/workflows/linux.yaml)

## Get, build and run

```bash
git clone https://github.com/JMazurkiewicz/GKOM-well-with-wheel.git
cd GKOM-well-with-wheel
```

### On Windows

Windows build requires at least Visual Studio 2019 (16.10).

```bat
rem Build with CMake
cmake -B build
cmake --build build --config Release

rem Show scene
copy build\Release\well-with-wheel.exe well-with-wheel
cd well-with-wheel
well-with-wheel.exe
```

### On Linux

Linux build requires at least GCC 10.

```bash
# Some of these dependencies may be needed (e.g. on Ubuntu)
sudo apt install libxrandr-dev libxinerama-dev libxi-dev libxcursor-dev libglu1-mesa-dev

# Build with CMake
cmake -B build -DCMAKE_BUILD_TYPE=Release
cmake --build build

# Show scene
cd build
./well-with-wheel
```

### For web

```bash
# Get Emscripten: https://emscripten.org/docs/getting_started/downloads.html

# Build with CMake
emcmake cmake -B build -DCMAKE_BUILD_TYPE=Release
cmake --build build

# Show scene
cd build
py -m http.server
# Open "http://localhost:8000/well-with-wheel.html" in your browser
```

## Overview

### Reference photo

<img src="docs/img/ref.png" alt="ref" width="600" />

### Finished Model

<img src="docs/img/finished.png" alt="finished" width="600" />

### Features

* Nothing on the scene is hard coded (everything is generated).
* The roof is randomly generated upon the start.
* The scene is customizable - parameters can be changed in `Startup/Well.cpp` file in `create*()` functions by modifying `basic*Model` objects (recompilation is required).

## Movement

Camera:

* WASD - change position
* Mouse - change view angle
* Space/Ctrl - up/down

Wheel:

* Left arrow - rotate left
* Right arrow - rotate right

Other:

* ESC - exit

## Branches

* `main` - the main branch with updated project
* `dev` - obsolete branch with minor fixes done after handing in assignment
* `original` - old branch with original, handed in, project (with docs and most of commit messages written in Polish)

## Team

Team working on `original` branch:

* Jakub Mazurkiewicz ([@JMazurkiewicz](https://github.com/JMazurkiewicz)) - model generation, program architecture, refactorization, introduction of C++20 features
* Damian Piotrowski ([@dam1508](https://github.com/dam1508)) - light, textures
* Jan Such ([@JeffHathford](https://github.com/JeffHathford)) - camera and movement

## Score

This was originally project for "Computer graphics (winter 2020)" course at Warsaw University of Technology.

Score: **25/30** (83.3%)
