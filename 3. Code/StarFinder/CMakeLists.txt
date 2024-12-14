# CMakeList.txt: проект CMake для StarFinder; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#

# Добавьте источник в исполняемый файл этого проекта.
add_executable (StarFinder "StarFinder.cpp" "StarFinder.h" "Model/Model.h" "DataStructures/DataStructures.h" "View/View.h" "Config/Config.h"  "Model/BaseModel/BasePixel.cpp"  "Model/BaseModel/BaseStar.cpp"  "Model/BaseModel/BaseParams.cpp" "Model/BaseModel/BaseModel.h"  "Model/BaseModel/BaseImage.cpp" "Model/BaseModel/BaseStars.cpp" "Errors/Errors.h" "Utils/Iterators.h"  )

if (CMAKE_VERSION VERSION_GREATER 3.25)
  set_property(TARGET StarFinder PROPERTY CXX_STANDARD 23)
endif()

# TODO: Добавьте тесты и целевые объекты, если это необходимо.
