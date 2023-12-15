#include "opencv2/opencv.hpp"

using namespace cv;
using namespace std;

void reduceColorAt(Mat& input, uchar table[]) { 
	for (int i = 0; i < input.rows; i++)
		for (int j = 0; j < input.cols; j++)
			input.at<uchar>(i, j) = table[input.at<uchar>(i, j)];
}

int main() {
	Mat img1 = imread("C:/MICT/img/Lenna.jpg", IMREAD_GRAYSCALE);
	imshow("Original", img1);

	/*
	// code 4.13
	uchar table[256];
	for (int i = 0; i < 256; ++i)
		table[i] = (uchar)((i / 100) * 100);
	*/
	
	// code 4.1
	Mat table(1, 256, CV_8U);

	uchar* p = table.ptr();
	for (int i = 0; i < 256; ++i)
		p[i] = (i / 50) * 50; // 6가지의 색 0, 50, 100, 150, 200, 250
	

	reduceColorAt(img1, p); // 포인터의 첫 주소값을 전달
	imshow("New", img1);
	waitKey(0);

	return 0;
}