#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

int main() {
	double alpha, beta;
	Mat src1, src2;

	cout << "Alpha [0.0-1.0] >> "; 
	cin >> alpha;

	src1 = imread("C:/MICT/img/test1.jpg");
	src2 = imread("C:/MICT/img/test2.jpg");

	/*
	if (src1.empty() || src2.empty()) {
		cout << "Images are not loaded properly." << endl;
		return 0;
	} */
	
	beta = (1.0 - alpha);

	Mat dst = Mat::zeros(src1.size(), src1.type());	// 결과 영상 출력
	// addWeighted() 함수 사용x, p122 참조
	for (int y = 0; y < src1.rows; y++)
		for (int x = 0; x < src1.cols; x++)
			for (int c = 0; c < 3; c++)
				dst.at<Vec3b>(y, x)[c] = saturate_cast<uchar>(alpha * (src1.at<Vec3b>(y, x)[c]) + beta * (src2.at<Vec3b>(y, x)[c]));

	//imshow("Original1", src1);
	//imshow("Original2", src2);
	imshow("선형 합성", dst);

	waitKey(0);
	return 0;
}