# CMakeList.txt: проект CMake для StarFinder; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#

# Добавьте источник в исполняемый файл этого проекта.
add_executable (StarFinder "main.cpp"  "Utils/Coordinates.h" "Utils/DisjointSet.h" "Utils/Pixels/Pixel.h" "Utils/Pixels/Gray/GrayPixel.h" "Utils/Pixels/Gray/GrayPixel.cpp" "Utils/Pixels/RGB/RGB_Pixel.h" "Utils/Pixels/RGB/RGB_Pixel.cpp" "Utils/Images/Image.h" "Filters/Gaussian/GaussianFilter.h" "Filters/Gaussian/GaussianFilter.cpp" "Filters/Gray/GrayFilter.h" "Filters/Gray/GrayFilter.cpp" "Filters/Median/MedianFilter.h" "Filters/Median/MedianFilter.cpp" "Filters/Sobel/SobelFilter.h" "Filters/Sobel/SobelFilter.cpp" "Errors/Errors.h" "Model/Star.h" "Model/Stars.h" "Model/SourceImage.h" "Model/Params.h" "Model/StarFinder.h" "Model/BaseModel/Star/BaseStar.h" "Model/BaseModel/Star/BaseStar.cpp" "Model/BaseModel/Stars/BaseStars.h" "Model/BaseModel/Stars/BaseStars.cpp" "Model/BaseModel/SourceImage/BaseSourceImage.h" "Model/BaseModel/SourceImage/BaseSourceImage.cpp"   "Model/BaseModel/StarFinder/BaseStarFinder.h" "Model/BaseModel/StarFinder/BaseStarFinder.cpp" "Model/BaseModel/SourceImage/BaseSourceImage.h" "Model/BaseModel/SourceImage/BaseSourceImage.cpp" "Model/BaseModel/Params/StarFinder/BaseStarFinderParams.h" "Model/BaseModel/Params/StarFinder/BaseStarFinderParams.cpp" "Model/BaseModel/Params/SourceImage/BaseSourceImageParams.h" "Model/BaseModel/Params/SourceImage/BaseSourceImageParams.cpp" "Utils/Images/MatrixImage.h" "Utils/Images/RGB_Image.h" "Utils/Images/GrayImage.h" "OperationSystem/OperationSystem.h" "Dependencies/lodepng/lodepng.h" "Dependencies/lodepng/lodepng.cpp")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET StarFinder PROPERTY CXX_STANDARD 20)
endif()

# TODO: Добавьте тесты и целевые объекты, если это необходимо.
