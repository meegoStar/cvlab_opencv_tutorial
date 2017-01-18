#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

int slider_value;
Mat src1, src2;

void on_trackbar(int, void*){
	double alpha = (double)slider_value / 100.0;
	double beta = (1.0 - alpha);
	Mat dst;

	addWeighted(src1, alpha, src2, beta, 0.0, dst);
	imshow("trackbar demo", dst);
}

int main(){
	src1 = imread("data/lake.jpg", CV_LOAD_IMAGE_UNCHANGED);
	src2 = imread("data/dusk.jpg", CV_LOAD_IMAGE_UNCHANGED);
	resize(src1, src1, Size(src1.cols / 6, src1.rows / 6));
	resize(src2, src2, Size(src2.cols / 6, src2.rows / 6));

	slider_value = 0;
	int slider_max_value = 100;

	namedWindow("trackbar demo", CV_WINDOW_KEEPRATIO);
	createTrackbar("Ratio", "trackbar demo", &slider_value, slider_max_value, on_trackbar);
	on_trackbar(slider_value, 0);

	waitKey(0);
	return 0;
}