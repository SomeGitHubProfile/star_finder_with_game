#include <iostream>
#include <string>

#include "Errors/Errors.h"
#include "OperationSystem/OperationSystem.h"
#include "Model/BaseModel/Params/SourceImage/BaseSourceImageParams.h"
#include "Model/BaseModel/SourceImage/BaseSourceImage.h"
#include "Model/BaseModel/StarFinder/BaseStarFinder.h"


using namespace std;

int main()
{
	string source_file_path;
	cout << "Input source file path\n";
	cin >> source_file_path;
	string result_file_path;
	cout << "Input result file path\n";
	cin >> result_file_path;
	try {
		model::base::params::BaseSourceImageParams image_params{source_file_path.c_str(), pixels::RGB_Pixel(188, 138, 232, 255), pixels::RGB_Pixel(188, 138, 232, 255), 0};
		image_params.init_source_image_dto();
		model::SourceImage* image = new model::base::BaseSourceImage(image_params);
		unsigned char red;
		unsigned char green;
		unsigned char blue;
		unsigned char alpha;
		cout << "Input color (red, green, blue, alpha). Pixels, which all color components will be greater, than color, will be interpreted as stars.\n";
		cin >> red >> green >> blue >> alpha;
		model::base::params::BaseStarFinderParams params{image, red, green, blue, alpha};
		model::StarFinder* star_finder = new model::base::BaseStarFinder(params);
		model::Stars* stars = star_finder->find_stars();
		images::Image* outlined_image = image->outline_stars(stars);
		operation_system::file_system.save_image(result_file_path.c_str(), outlined_image);
		cout << "Stars found\n";
		cout << "Number of stars: " << stars->get_size() << '\n';
		delete outlined_image;
		delete stars;
		delete star_finder;
		delete image;
		cout << "Without errors\n";
	} catch (const errors::BaseError& e) {
		cout << "Error catched " << e.text << '\n';
	}
	cout << "Finishing main...\n";
	return 0;
}
