#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

void find_face(string, string);

int main()
{
	string photos[] = {
		"../photos/photo1.jpg",
		"../photos/photo2.jpg"/*,
		"../photos/photo3.jpg",
		"../photos/photo4.jpg",
		"../photos/photo5.jpg",
		"../photos/photo6.jpg"*/
	};
	string templates[] = {
		"../templates/full_face.jpg",
		"../templates/eyes_and_nose.jpg",
		"../templates/eye.jpg"
	};
	
	for (const string &photo : photos )
		for (const string &templ : templates) {
			find_face(photo, templ);
		}
	
	return 0;
}

void find_face(string photo_img, string templ_img) {
	Mat photo;
	Mat templ;
	try {
		photo = imread(photo_img, 0);
		templ = imread(templ_img, 0);
		if (photo.data == NULL || templ.data == NULL)
			throw 0;
	}
	catch(...) {
		cout << "Image has no data!" << endl;
		exit(-1);
	}
	
	Mat result;
	int templWidth = templ.size().width;
	int templHeight = templ.size().height;
	double minVal, maxVal;
	Point minLoc, maxLoc, topLeft, bottomRight;
	namedWindow("result_window", WINDOW_AUTOSIZE);

	for (int method = 0; method < 6; ++method) {
		matchTemplate(photo, templ, result, method);

		minMaxLoc(result, &minVal, &maxVal, &minLoc, &maxLoc);

		if (method == 0 || method == 1)
			topLeft = minLoc;
		else
			topLeft = maxLoc;
		bottomRight = Point(topLeft.x + templWidth, topLeft.y + templHeight);

		rectangle(photo, topLeft, bottomRight, 255);

		imshow("result_window", photo);

		waitKey(0);
	}
}