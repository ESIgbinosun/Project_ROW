cmake_minimum_required(VERSION 3.20)
project(Project_ROW C)

set(CMAKE_C_STANDARD 11)

include_directories(..)

add_executable(Project_ROW
        main.c
        motor.h Wheel_encoder/waterPomp.cpp Water_pomp/waterPomp.c Water_pomp/water_level_sensor.c Water_pomp/ADC.cpp Water_pomp/ADC.h Water_pomp/WaterLevel.cpp)
