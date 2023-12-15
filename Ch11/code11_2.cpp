#include "opencv2/opencv.hpp"
#include <iostream>

using namespace std;
using namespace cv;

/*
int threshold_value = 128;
int threshold_type = 0;
const int max_type = 4;
const int max_binary_value = 255;
Mat src, src_gray, dst;

static void MyThreshold(int, void*) {
	threshold(src, dst, threshold_value, max_binary_value, threshold_type);
	imshow("result", dst);
}
*/

int main() {
	/*
	// Code 11.2
	src = imread("C:/MICT/img/lenna.jpg", IMREAD_GRAYSCALE);
	imshow("src", src);

	namedWindow("result", WINDOW_AUTOSIZE);
	createTrackbar("Type: \n 0: Binary \n 1: Binary Inverted \n 2: Truncate \n 3: To Zoro \n 4: To Zero Inverted",
		"result", &threshold_type, max_type, MyThreshold);

	MyThreshold(0, 0);
	*/

	// Code 11.3
	Mat src = imread("C:/MICT/img/book1.jpg", IMREAD_GRAYSCALE);
	Mat img, th1, th2, th3, th4;
	medianBlur(src, img, 5);
	threshold(img, th1, 127, 255, THRESH_BINARY);
	adaptiveThreshold(img, th2, 255, ADAPTIVE_THRESH_MEAN_C, THRESH_BINARY, 11, 2);
	adaptiveThreshold(img, th3, 255, ADAPTIVE_THRESH_GAUSSIAN_C, THRESH_BINARY, 11, 2);

	imshow("Original", src);
	imshow("Global Thresholding", th1);
	imshow("Adaptive Mean", th2);
	imshow("Adaptive Gaussian", th3);

	waitKey();
	return 0;
}