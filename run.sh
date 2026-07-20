#!/bin/bash

cmake --build build

SDL_VIDEODRIVER=x11 ./build/Sandbox/Sandbox