#include <iostream>

#include "Utils/Pixels/RGB/RGB_Pixel.h"
#include "Utils/Images/GrayImage.h"
#include "Filters/Gaussian/GaussianFilter.h"
#include "Filters/Gray/GrayFilter.h"
#include "Filters/Sobel/SobelFilter.h"

#include "Model/StarFinder.h"

#include "Model/BaseModel/SourceImage/BaseSourceImage.h"
#include "Model/BaseModel/StarFinder/BaseStarFinder.h"

#include "Utils/Images/RGB_Image.h"

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

	pixels::RGB_Pixel** matrix = new pixels::RGB_Pixel*[5];
	for (int i = 0; i < 5; ++i) {
		matrix[i] = new pixels::RGB_Pixel[5];
	}

	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 5; ++j) {
			matrix[i][j] = pixels::RGB_Pixel(50 * i, 50 * j, 0, 255);
		}
	}

	images::RGB_ImageDto dto{{5, 5}, matrix};

	cout << "Red: " << (int)dto.matrix[4][2].get_red() << '\n';

	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 5; ++j) {
			cout << (int)matrix[i][j].get_red() << " " << (int)matrix[i][j].get_green() << " --- ";
		}
		cout << "\n";
	}

	cout << "Tesing virtual array))\n";

	for (int i = 0; i < 5; ++i) {
		delete[] matrix[i];
	}
	delete[] matrix;
	return 0;
}
