# CMakeList.txt: проект CMake для HomeWork_32.5.2; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#

# Добавьте источник в исполняемый файл этого проекта.
add_executable (HomeWork_32.5.2 "main.cpp" )

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET HomeWork_32.5.2 PROPERTY CXX_STANDARD 20)
endif()

set(JSON_BuildTests OFF CACHE INTERNAL "")

add_subdirectory(nlohmann_json)


target_link_libraries(HomeWork_32.5.2 PRIVATE nlohmann_json::nlohmann_json)


# TODO: Добавьте тесты и целевые объекты, если это необходимо.
