#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

int main() {
	/*
	// code 9.4
	Mat img = imread("C:/MICT/img/plane.jpg");

	Mat imgHSV;
	cvtColor(img, imgHSV, COLOR_BGR2HSV);

	Mat imgThresholded;
	inRange(imgHSV, Scalar(80, 0, 0), Scalar(110, 255, 255), imgThresholded);

	imshow("imgHSV", imgHSV);
	imshow("Thresholded Imgae", imgThresholded);
	imshow("Original", img);
	*/

	/*
	// code 9.5 -> ÄÚµå ÀÌÇØÇÏ±â! 
	Mat img = imread("C:/MICT/img/chroma.jpg");
	Mat img2 = imread("C:/MICT/img/beach.png");

	Mat converted;
	cvtColor(img, converted, COLOR_BGR2HSV);
	Mat greenScreen = converted.clone();
	inRange(converted, Scalar(60 - 10, 100, 100), Scalar(60 + 10, 255, 255), greenScreen);

	Mat dst, dst1, inverted;
	bitwise_not(greenScreen, inverted);
	bitwise_and(img, img, dst, inverted);
	bitwise_or(dst, img2, dst1, greenScreen);
	imshow("prev dst1", dst1);
	bitwise_or(dst, dst1, dst1);

	imshow("converted", converted);
	imshow("img", img);
	imshow("green", greenScreen);
	imshow("dst", dst);
	imshow("dst1", dst1);
	*/

	// code 9.6
	VideoCapture cap("C:/MICT/img/tennis_ball.mp4");
	if (!cap.isOpened()) return -1;

	for (;;) {
		Mat imgHSV;
		Mat frame;
		cap >> frame;
		cvtColor(frame, imgHSV, COLOR_BGR2HSV);

		Mat imgThresholded;
		inRange(imgHSV, Scalar(30, 10, 10), Scalar(38, 255, 255), imgThresholded);

		imshow("frame", frame);
		imshow("dst", imgThresholded);
		if (waitKey(30) >= 0) break;
	}

	waitKey(0);
	return 0;
}
