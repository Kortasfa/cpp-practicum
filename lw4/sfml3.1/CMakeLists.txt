add_executable(sfml3.1 main.cpp)

set(SFML_STATIC_LIBRARIES TRUE)

find_package(Freetype)
find_package(JPEG)
find_package(SFML 2 COMPONENTS window graphics system)

target_compile_features(sfml3.1 PUBLIC cxx_std_17)
target_compile_definitions(sfml3.1 PRIVATE SFML_STATIC)

target_link_libraries(sfml3.1 ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})