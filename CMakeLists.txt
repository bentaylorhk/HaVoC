# HaVoC Emulator Project
# Benjamin Michael Taylor
# 2021

cmake_minimum_required(VERSION 3.10)

project(
  HaVoC
  VERSION 0.1
  DESCRIPTION "NES/Famicon Emulator created in C++")

add_subdirectory(src)

add_executable(HaVoC src/main.cpp)