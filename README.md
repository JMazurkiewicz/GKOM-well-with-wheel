# Well with wheel

[![Windows build](https://github.com/JMazurkiewicz/GKOM-well-with-wheel/actions/workflows/windows.yaml/badge.svg)](https://github.com/JMazurkiewicz/GKOM-well-with-wheel/actions/workflows/windows.yaml)
[![Linux build](https://github.com/JMazurkiewicz/GKOM-well-with-wheel/actions/workflows/linux.yaml/badge.svg)](https://github.com/JMazurkiewicz/GKOM-well-with-wheel/actions/workflows/linux.yaml)

## Get, build and run

```bash
git clone https://github.com/JMazurkiewicz/GKOM-well-with-wheel.git
cd GKOM-well-with-wheel
git submodule init
git submodule update
```

### On Windows

Windows build requires at least Visual Studio 2019 (16.10).

```bat
cmake -B build
cmake --build build --config Release
copy build\Release\well-with-wheel.exe well-with-wheel

rem And run
cd well-with-wheel
well-with-wheel.exe
```

### On Linux

Linux build requires at least GCC 10.

```bash
# Some of those dependencies may be needed (e.g. on Ubuntu)
sudo apt install libxrandr-dev libxinerama-dev libxi-dev libxcursor-dev libglu1-mesa-dev

cmake -B build -DCMAKE_BUILD_TYPE=Release
cmake --build build
cp build/well-with-wheel well-with-wheel

# And run
cd well-with-wheel
./well-with-wheel
```

## Overview

### Reference photo

![ref](docs/img/ref.png)

### Finished Model

![finished](docs/img/finished.png)

## Movement

Camera:

* WASD - change position
* Mouse - change view angle
* Space/Ctrl - up/down

Wheel:

* Left arrow - rotate left
* Right arrow - rotate right

## Branches

* `main` - the main branch with updated project
* `dev` - obsolete branch with minor fixes done after handing in assignment
* `original` - old branch with original, handed in, project

## Team

Team working on `original` branch:

* Jakub Mazurkiewicz ([@JMazurkiewicz](https://github.com/JMazurkiewicz)) - model generation, program architecture, refactorization, introduction of C++20 features
* Damian Piotrowski ([@dam1508](https://github.com/dam1508)) - light, textures
* Jan Such ([@JeffHathford](https://github.com/JeffHathford)) - camera and movement
