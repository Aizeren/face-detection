#include "templateMatching.h"

int main()
{
	const string photosDir = "../photos/";
	const string templatesDir = "../templates3/";
	const string resultsDir = "../results/";
	const string photos[] = {
		"photo1.jpg",
		"photo2.jpg",
		"photo3.jpg",
		"photo4.jpg",
		"photo5.jpg",
		"photo6.jpg",
		"photo7.jpg",
		"photo8.jpg"
	};
	const string templates[] = {
		"full_face.jpg",
		"eyes_and_nose.jpg",
		"eye.jpg"
	};

	for (const string& photo : photos)
		for (const string& templ : templates)
			find_face(photo, photosDir, templ, templatesDir, resultsDir, 3);

	return 0;
}