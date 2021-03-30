# Havoc Emulator Project
# Benjamin Michael Taylor
# 2021

set(cpu_source_files
    cpu.cpp
    cpu.h
    instructions.cpp
    instructions.h
)

add_library(cpu ${cpu_source_files})