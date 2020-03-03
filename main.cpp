#include "templateMatching.h"
#include "ViolaJones.h"

int main(int argc, const char ** argv)
{
	bool isTemplMatch = 1;
	bool isViolaJones = 0;

	if (isTemplMatch) {
		const string photosDir = "../photos/";
		const string templatesDir = "../templates/";
		const string resultsDir = "../results/";
		const string photos[] = {
			"photo1.jpg",
			"photo2.jpg",
			"photo3.jpg",
			"photo4.jpg",
			"photo5.jpg",
			"photo6.jpg",
			"photo7.jpg",
			"photo8.jpg",
			"photo9.jpg",
			"photo10.jpg",
			"photo11.jpg"
		};
		const string templates[] = {
			"full_face.jpg",
			"eyes_and_nose.jpg",
			"eye.jpg"
		};

		for (const string& photo : photos)
			for (const string& templ : templates)
				find_face_templMatch(photo, photosDir, templ, templatesDir, resultsDir, 3, 0.9, 1.2);
	}

	if (isViolaJones) {
		find_face_in_stream_ViolaJones(1);
	}
	
	return 0;
}