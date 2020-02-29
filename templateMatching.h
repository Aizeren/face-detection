#pragma once
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/videoio.hpp>
#include <filesystem>
#include <iostream>
#include <map>

using namespace cv;
using namespace std;

//Find face on photo using template matching
void find_face_templMatch(string, string, string, string, string, int);