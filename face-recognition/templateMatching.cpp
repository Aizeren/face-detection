#include "templateMatching.h"

void find_face(string photo_img, string templ_img, int method) {
	if (method > 5 || method < 0)
		exit(-2);
	Mat photo;
	Mat templ;
	try {
		photo = imread(photo_img, 0);
		templ = imread(templ_img, 0);
		if (photo.data == NULL || templ.data == NULL)
			throw 0;
	}
	catch (...) {
		cout << "Image has no data!" << endl;
		exit(-1);
	}
	
	{
		double scale;
		if (photo.size().height < photo.size().width)
			scale = 0.5 * (photo.size().height) / (templ.size().height);
		else 
			scale = 0.5 * (photo.size().width) / (templ.size().width);
		resize(templ, templ, Size(), scale, scale);
	}
	Mat scaledTempl(templ);
	Mat result;
	int scaledTemplWidth = scaledTempl.size().width,
		scaledTemplHeight = scaledTempl.size().height;
	double minVal, maxVal, bestMinVal = DBL_MAX, bestMaxVal = DBL_MIN;
	Point minLoc, maxLoc, topLeft, bottomRight,
		bestMinLoc(INT_MAX, INT_MAX), bestMaxLoc(INT_MIN, INT_MIN);
	const map <int, string> methodsMap = { {0, "SQDIFF"},
											{1, "SQDIFF_NORMED"},
											{2, "CCORR"},
											{3, "CCORR_NORMED"},
											{4, "CCOEFF"},
											{5, "CCOEFF_NORMED"} };

	for (double scale = 0.2; scale < 1.7; scale += 0.1) {
		resize(templ, scaledTempl, Size(), scale, scale);

		matchTemplate(photo, scaledTempl, result, method);
		minMaxLoc(result, &minVal, &maxVal, &minLoc, &maxLoc);

		if (method == 0 || method == 1) {
			if (minVal < bestMinVal) {
				bestMinVal = minVal;
				bestMinLoc = minLoc;
				scaledTemplHeight = scaledTempl.size().height;
				scaledTemplWidth = scaledTempl.size().width;
			}
		}
		else
			if (maxVal > bestMaxVal) {
				bestMaxVal = maxVal;
				bestMaxLoc = maxLoc;
				scaledTemplHeight = scaledTempl.size().height;
				scaledTemplWidth = scaledTempl.size().width;
			}
	}
	if (method == 0 || method == 1)
		topLeft = bestMinLoc;
	else
		topLeft = bestMaxLoc;
	bottomRight = Point(topLeft.x + scaledTemplWidth, topLeft.y + scaledTemplHeight);

	rectangle(photo, topLeft, bottomRight, 255);

	imshow(methodsMap.at(method) + " " + photo_img + " " + templ_img, photo);

	waitKey(0);

	return;
}