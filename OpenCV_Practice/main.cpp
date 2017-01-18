#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

int main()
{
	Mat frame;
	VideoCapture cap("data/jaguar.avi");

	if (!cap.isOpened()) {
		cout << "Cannot open the video" << endl;
		return -1;
	}

	for (;;) {
		cap.read(frame);

		if (frame.rows > 0) imshow("Video Frame", frame);
		else break;

		waitKey(30);
	}
	return 0;
}