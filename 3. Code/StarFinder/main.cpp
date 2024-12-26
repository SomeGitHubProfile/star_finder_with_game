#include <iostream>
#include <string>

#include "Utils/Pixels/RGB/RGB_Pixel.h"
#include "Utils/Images/GrayImage.h"
#include "Filters/Gaussian/GaussianFilter.h"
#include "Filters/Gray/GrayFilter.h"
#include "Filters/Sobel/SobelFilter.h"

#include "Model/StarFinder.h"

#include "Model/BaseModel/SourceImage/BaseSourceImage.h"
#include "Model/BaseModel/StarFinder/BaseStarFinder.h"

#include "Utils/Images/RGB_Image.h"
#include "Utils/Images/MatrixImageDto.h"

#include "Errors/Errors.h"

using namespace std;

int main()
{
	string s;
	cin >> s;
	cout << "Hello " << s << '\n';
	try {
		model::base::params::BaseSourceImageParams image_params{s.c_str(), pixels::RGB_Pixel(), pixels::RGB_Pixel(), 0};
		image_params.init_source_image_dto();
		model::SourceImage* image = new model::base::BaseSourceImage(image_params);
		model::base::params::BaseStarFinderParams params{image};
		model::StarFinder* t = new model::base::BaseStarFinder(params);
		delete image;
		delete t;
		cout << "Without errors\n";
	} catch (const errors::BaseError& e) {
		cout << "Error catched " << e.text << '\n';
	}
	cout << "Finishing main...\n";
	return 0;
}
