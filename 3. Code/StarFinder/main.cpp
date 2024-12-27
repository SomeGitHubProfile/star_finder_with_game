#include <iostream>
#include <string>

#include "Errors/Errors.h"


using namespace std;

int main()
{
	string s;
	cin >> s;
	cout << "Hello " << s << '\n';
	try {
		/*model::base::params::BaseSourceImageParams image_params{s.c_str(), pixels::RGB_Pixel(), pixels::RGB_Pixel(), 0};
		image_params.init_source_image_dto();
		model::SourceImage* image = new model::base::BaseSourceImage(image_params);
		model::base::params::BaseStarFinderParams params{image, 5};
		model::StarFinder* star_finder = new model::base::BaseStarFinder(params);
		model::Stars* stars = star_finder->find_stars();
		cout << "Stars found\n";
		cout << "Number of stars: " << stars->get_size() << '\n';
		delete stars;
		delete image;
		delete star_finder;*/
		cout << "Without errors\n";
	} catch (const errors::BaseError& e) {
		cout << "Error catched " << e.text << '\n';
	}
	cout << "Finishing main...\n";
	return 0;
}
