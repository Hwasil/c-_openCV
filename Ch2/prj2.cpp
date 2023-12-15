#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
using namespace std;

int main() {
	Mat src = imread("Lenna.jpg", IMREAD_COLOR);
	if (src.empty()) { cout << "영상을 읽을 수 없음" << endl; }
	imshow("src", src);

	Mat gray, dst;
	cvtColor(src, gray, COLOR_BGR2GRAY);

	imshow("gray", gray);
	imwrite("gray.jpg", gray);

	flip(src, dst, 1);
	imshow("filp", dst);

	Mat image = Mat(400, 600, CV_8UC3, Scalar(0, 0, 0));

	// 도형 그리기
	line(image, Point(100, 100), Point(300, 300), Scalar(0, 0, 255), 7);
	rectangle(image, Point(250, 30), Point(450, 200), Scalar(0, 255, 0), 5);
	circle(image, Point(100, 300), 60, Scalar(255, 0, 0), 3);
	ellipse(image, Point(250, 300), Point(100, 60), 127, 0, 360, Scalar(255, 255, 255), 5);

	imshow("Image", image);

	waitKey(0);
	return 0;
}