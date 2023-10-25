# Минимальная версия CMake: 3.8
cmake_minimum_required(VERSION 3.8 FATAL_ERROR)

# Имя проекта: lw5
project(lw5)

# Подкаталог 00 содержит ещё один CMakeLists.txt
add_subdirectory(workshop1.1)
add_subdirectory(workshop1.2)
add_subdirectory(workshop1.3)
add_subdirectory(workshop1.4)