#include "templateMatching.h"

int main()
{
	string photos[] = {
		"../photos/photo1.jpg",
		"../photos/photo2.jpg",
		"../photos/photo3.jpg",
		"../photos/photo4.jpg",
		"../photos/photo5.jpg",
		"../photos/photo6.jpg"
	};
	string templates[] = {
		"../templates/full_face.jpg",
		"../templates/eyes_and_nose.jpg",
		"../templates/eye.jpg"
	};

	for (const string& photo : photos)
		for (const string& templ : templates)
			find_face(photo, templ, 5);

	return 0;
}