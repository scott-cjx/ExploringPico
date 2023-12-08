#!/bin/sh

sdk_location="path/to/pico-sdk"
proj_location="path/to/project"
project_name="project_name"

docker run --rm -it \
 -v $sdk_location:/pico-sdk \
 -v $proj_location:/project \
 xingrz/rpi-pico-builder:latest \
 bash -c "mkdir -p build && cd build && cmake .. && make ${project_name}"
