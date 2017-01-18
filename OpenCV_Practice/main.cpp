#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

int main()
{
	VideoCapture cap(0); // open the default camera
	// VideoCapture cap(1); // open the second camera

	if (!cap.isOpened())  // check if we succeeded
		return -1;

	Mat edges;
	namedWindow("my camera", 1);
	for (;;)
	{
		Mat frame;
		cap >> frame; // get a new frame from camera
		imshow("my camera", frame);
		if (waitKey(30) >= 0) break; // press any key to close window
	}

	// the camera will be deinitialized automatically in VideoCapture destructor
	return 0;
}