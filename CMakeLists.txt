cmake_minimum_required(VERSION 3.13)

set(PROJECT_NAME exploring-pico)

# initialize pico-sdk from GIT
# (note this can come from environment, CMake cache etc)
set(PICO_SDK_FETCH_FROM_GIT on)

# initialize the SDK based on PICO_SDK_PATH
# note: this must happen before project()
include(pico_sdk_import.cmake)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

if (PICO_SDK_VERSION_STRING VERSION_LESS "1.3.0")
message(FATAL_ERROR "Raspberry Pi Pico SDK version 1.3.0 (or later) required. Your version is ${PICO_SDK_VERSION_STRING}")
endif()

project(${PROJECT_NAME} C CXX ASM)

# initialize the Raspberry Pi Pico SDK
pico_sdk_init()

include(example_auto_set_url.cmake)

include_directories(
    inc
    src
)

add_executable(${PROJECT_NAME}
    ${CMAKE_CURRENT_LIST_DIR}/src/main.cpp
    # Library executables
    inc/mcp2515/mcp2515.cpp
)

# Add MCP2515 Lib
target_include_directories(${PROJECT_NAME} PUBLIC inc/)

target_link_libraries(${PROJECT_NAME} 
    pico_stdlib
    pico_stdio
    hardware_spi
)

pico_enable_stdio_uart(${PROJECT_NAME} 0)
pico_enable_stdio_usb(${PROJECT_NAME} 1)

# create map/bin/hex file etc.
pico_add_extra_outputs(${PROJECT_NAME})