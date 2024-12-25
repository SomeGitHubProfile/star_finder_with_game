#include <iostream>

#include "Utils/Pixels/RGB/RGB_Pixel.h"
#include "Utils/Images/GrayImage.h"
#include "Filters/Gaussian/GaussianFilter.h"
#include "Filters/Gray/GrayFilter.h"
#include "Filters/Sobel/SobelFilter.h"

#include "Model/StarFinder.h"

#include "Model/BaseModel/SourceImage/BaseSourceImage.h"
#include "Model/BaseModel/StarFinder/BaseStarFinder.h"

using namespace std;

int main()
{
	cout << "test\n";
	model::SourceImage* image = new model::base::BaseSourceImage({1, 2});
	model::base::params::BaseStarFinderParams params = model::base::params::BaseStarFinderParams(image);
	model::StarFinder* t = new model::base::BaseStarFinder(params);
	images::GrayImage img = images::GrayImage({1, 2});
	cout << img.shape.y;
	pixels::RGB_Pixel p = pixels::RGB_Pixel(100, 200, 300, 400);
	cout << p.get_red();
	cout << "Hello CMake." << endl;
	delete image;
	delete t;
	return 0;
}
