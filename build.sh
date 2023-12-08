#!/bin/sh

sdk_location="/home/s/Desktop/pico/pico-sdk"
proj_location="/home/s/Desktop/pico/ExploringPico"
project_name="exploring-pico"
TARGET_PROJECET="RX"

docker run --rm -it \
 -v $sdk_location:/pico-sdk \
 -v $proj_location:/project \
 xingrz/rpi-pico-builder:latest \
 bash -c "mkdir -p build && cd build && cmake .. -DTARGET_PROJECT=${TARGET_PROJECET} && make ${project_name}"
