#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;


int main() {
	// code 7.2
	Mat src = imread("C:/MICT/img/lenna.jpg", IMREAD_COLOR);
	Mat dst = Mat::zeros(Size(src.cols, src.rows), src.type());

	for (int y = 0; y < src.rows; y++) {
		for (int x = 0; x < src.cols; x++) {
			for (int c = 0; c < 3; c++) {
				const int newX = x + 20;
				const int newY = y + 60;
				if (newX > 0 && newY > 0 && newX < src.cols && newY < src.rows) {
					dst.at<Vec3b>(newY, newX)[c] = src.at<Vec3b>(y, x)[c];
				}
			}
		}
	}
	imshow("src", src);
	imshow("dst", dst);

	/*
	// code 7.3
	Mat src = imread("C:/MICT/img/lenna.jpg", IMREAD_COLOR);
	Mat dst = Mat::zeros(Size(src.cols * 2, src.rows * 2), src.type());

	for (int y = 0; y < dst.rows; y++) {
		for (int x = 0; x < dst.cols; x++) {
			for (int c = 0; c < 3; c++) {
				const int newX = x / 2.0;
				const int newY = y / 2.0;
				dst.at<Vec3b>(y, x)[c] = src.at<Vec3b>(newY, newX)[c];
			}
		}
	}
	
	imshow("Image", src);
	imshow("Scaled", dst);
	*/
	waitKey(0);
	return 1;
}