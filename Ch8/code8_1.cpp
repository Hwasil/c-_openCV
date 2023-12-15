#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

int main() {
	Mat src, dst, erosion_dst, dilatition_dst;
	src = imread("C:/MICT/img/morph.jpg", IMREAD_GRAYSCALE);

	threshold(src, dst, 127, 255, THRESH_BINARY);
	imshow("BINARY", dst);

	Mat element = getStructuringElement(MORPH_RECT, Size(3, 3), Point(-1, -1));

	erode(dst, erosion_dst, element);
	dilate(dst, dilatition_dst, element);

	imshow("erode", erosion_dst);
	imshow("dilate", dilatition_dst);

	waitKey(0);
	return 0;
}