#define _CRT_SECURE_NO_WARNINGS
#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
using namespace std;

int main() {
	Mat A = imread("image2.jpg");
	Mat B = imread("logo.png");

	// center
	Mat roi(A, Rect(A.cols/2, A.rows/2, B.cols, B.rows));
	Mat roi1(A, Rect(0, 0, B.cols, B.rows));
	Mat roi2(A, Rect(A.cols - B.cols, 0, B.cols, B.rows));
	Mat roi3(A, Rect(0, A.rows - B.rows, B.cols, B.rows));
	Mat roi4(A, Rect(A.cols - B.cols, A.rows - B.rows, B.cols, B.rows));

	B.copyTo(roi);

	B.copyTo(roi1);

	B.copyTo(roi2);

	B.copyTo(roi3);

	B.copyTo(roi4);
	
	imshow("result", A);
	waitKey(0);
	return 0;
}