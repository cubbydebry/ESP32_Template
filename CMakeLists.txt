cmake_minimum_required(VERSION 3.16)

#=== ESP32 Template Cubby DeBry 2025 ===

if(WIN32)
    set(USERHOME $ENV{USERPROFILE})
else()
    set(USERHOME $ENV{HOME})
endif()

# Check for ESP-IDF
if (DEFINED ENV{IDF_PATH})
    set(IDF_PATH $ENV{IDF_PATH})
else()
    set(IDF_PATH ${CMAKE_CURRENT_LIST_DIR}/lib/esp-idf)
endif()

#==============================================

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
SET(CMAKE_C_EXTENSIONS ON)
SET(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Complier definitions
# add_compile_definitions()

# Import IDF toolchain
include(${IDF_PATH}/tools/cmake/project.cmake)

# Project name
project(esp32_template C CXX ASM)

# Project Include directories
# include_directories(${CMAKE_CURRENT_LIST_DIR}/include)

# Add subdirectories

# Testing
# include(CTest)
# add_subdirectory(test)