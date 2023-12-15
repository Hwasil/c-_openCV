#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

// 화소 접근 방식
int main() {
	double alpha = 1.0;
	int beta = 0;

	Mat image = imread("C:/MICT/img/contrast.jpg", IMREAD_GRAYSCALE); 
	Mat oimage = Mat::zeros(image.size(), image.type());

	cout << "알파값 입력 : [1.0 - 3.0] >> "; cin >> alpha;
	cout << "베타값 입력 : [0 - 100] >> "; cin >> beta;

	/* 4.5
	for (int y = 0; y < image.rows; y++) {
		for (int x = 0; x < image.cols; x++) {
			for (int c = 0; c < 3; c++) {
				oimage.at<Vec3b>(y, x)[c] = saturate_cast<uchar>(alpha * (image.at<Vec3b>(y, x)[c] + beta));
			}
		}
	} */

	// 4.6 convertTo 함수 사용
	image.convertTo(oimage, -1, alpha, beta);

	imshow("Original", image);
	imshow("New", oimage);

	waitKey();
	return 0;
}
