#pragma once
#include <opencv2/objdetect.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/videoio.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int find_face_in_stream_ViolaJones(float scale);
void findFaceAndDisplay(Mat&, CascadeClassifier&);