cmake_minimum_required(VERSION 3.13)

# initialize the SDK based on PICO_SDK_PATH
# note: this must happen before project()
include(pico_sdk_import.cmake)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

if (PICO_SDK_VERSION_STRING VERSION_LESS "1.3.0")
message(FATAL_ERROR "Raspberry Pi Pico SDK version 1.3.0 (or later) required. Your version is ${PICO_SDK_VERSION_STRING}")
endif()

project(my_project C CXX)

# initialize the Raspberry Pi Pico SDK
pico_sdk_init()

include(example_auto_set_url.cmake)

# rest of your project

include_directories(
        inc
        src
        )
        
add_executable(project_name
        ${CMAKE_CURRENT_LIST_DIR}/src/main.cpp
        )

target_link_libraries(project_name 
        )

# create map/bin/hex file etc.
pico_add_extra_outputs(project_name)

