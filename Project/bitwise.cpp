// 202195027 오화실
#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

int main() {
	Mat img1 = Mat::zeros(Size(500, 500), CV_8UC1);
	Mat img2 = Mat::zeros(Size(500, 500), CV_8UC1);

	// 관심 영역 지정
	circle(img1, Point(250, 250), 180, Scalar(255, 255, 255), -1);
	imshow("img1", img1);

	Mat t2 = img2(Range(0, 500), Range(0, 250));	// 관심영역을 별도의 Mat 객체로 생성
	t2 = 255;										// 관심영역의 모든 화소 255
	imshow("img2", img2);

	Mat result;
	bitwise_or(img1, img2, result);
	imshow("bitwise_or", result);

	bitwise_and(img1, img2, result);
	imshow("bitwise_and", result);

	bitwise_xor(img1, img2, result);
	imshow("bitwise_xor", result);

	bitwise_not(img1, result);
	imshow("bitwise_not", result);

	waitKey(0);
	return 0;
}
