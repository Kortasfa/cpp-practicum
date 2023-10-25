# Минимальная версия CMake: 3.8
cmake_minimum_required(VERSION 3.8 FATAL_ERROR)

# Имя проекта: lw4
project(lw4)

# Подкаталог 00 содержит ещё один CMakeLists.txt
add_subdirectory(02)
add_subdirectory(03)
add_subdirectory(04)
add_subdirectory(sfml3.1)
add_subdirectory(sfml3.2)
add_subdirectory(sfml3.3)
