# CMakeList.txt: проект CMake для StarFinder; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#

# Добавьте источник в исполняемый файл этого проекта.
add_executable (StarFinder "StarFinder.cpp" "StarFinder.h" "Model/Model.h" "DataStructures/DataStructures.h" "View/View.h")

if (CMAKE_VERSION VERSION_GREATER 3.25)
  set_property(TARGET StarFinder PROPERTY CXX_STANDARD 23)
endif()

# TODO: Добавьте тесты и целевые объекты, если это необходимо.
