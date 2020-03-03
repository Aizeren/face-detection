#include "ViolaJones.h"
#include <time.h>

int find_face_in_stream_ViolaJones(float scale) {
	CascadeClassifier face_cascade;
	int cameraNum = 0;
	String faceCascadePath = "C:/opencv/sources/data/haarcascades/haarcascade_frontalface_default.xml";
	VideoCapture capture;
	Mat frame;

	if (!face_cascade.load(faceCascadePath))
	{
		cout << "Error loading face cascade" << endl;
		exit(-1);
	}

	capture.open(cameraNum);
	if (!capture.isOpened()) {
		cout << "Error opening capture" << endl;
		exit(-1);
	}
	/*int frames = 0;
	time_t timestart = time(NULL);*/
	while (capture.read(frame)) {
		
		if (frame.empty()) {
			cout << "Frame is empty" << endl;
			break;
		}
		resize(frame, frame, Size(), scale, scale);
		findFaceAndDisplay(frame, face_cascade);
		
		
		if (waitKey(1) == 32) { //space pressed
			break;
		}
		/*if (time(NULL) - timestart >= 1) {
			cout << frames << endl;
			timestart = time(NULL);
			frames = 0;
			cout << frame.size() << endl << endl;
		}
		++frames;*/
	}

	return 0;
}

void findFaceAndDisplay(Mat &frame, CascadeClassifier &classifier) {
	//Mat frameGray(frame);
	vector<Rect> faces;

	//cvtColor(frame, frameGray, COLOR_BGR2GRAY);
	//equalizeHist(frameGray, frameGray);

	//classifier.detectMultiScale(frameGray, faces);

	cvtColor(frame, frame, COLOR_BGR2GRAY);

	classifier.detectMultiScale(frame, faces);

	for (size_t i = 0; i < faces.size(); ++i) {
		rectangle(frame, Rect(faces[i].x, faces[i].y, faces[i].width, faces[i].height), Scalar(255, 255, 255), 5);
	}

	imshow("Viola Jones face detecting", frame);
	return;
}