# HaVoC Emulator Project
# Benjamin Michael Taylor
# 2021

cmake_minimum_required(VERSION 3.10)

project(
  HaVoC
  VERSION 0.1
  DESCRIPTION "NES/Famicon Emulator created in C++")

include_directories(include)

add_subdirectory(src)