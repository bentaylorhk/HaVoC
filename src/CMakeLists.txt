# HaVoC Emulator Project
# Benjamin Michael Taylor
# 2021

add_subdirectory(apu)
add_subdirectory(cpu)
add_subdirectory(mmu)
add_subdirectory(ppu)

add_executable(HaVoC main.cpp)

target_link_libraries(HaVoC cpu)