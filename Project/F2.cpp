#include "opencv2/opencv.hpp"
#include <iostream>

using namespace std;
using namespace cv;

/* 2.
* 블러링 : 평균값 필터링, 3 * 3, 사용자 함수 컨볼루션 사용
* sobel 에지
*/

Mat userConolution(Mat input, Mat mask) {
	Mat output;

	int imgRows = input.rows;
	int imgCols = input.cols;
	int maskRows = mask.rows;
	int maskCols = mask.cols;

	output = Mat::zeros(imgRows, imgCols, CV_32F);

	for (int i = 0; i < imgRows; i++) {
		for (int j = 0; j < imgCols; j++) {
			float sum = 0;

			for (int k = 0; k < maskRows; k++) {
				for (int l = 0; l < maskCols; l++) {
					if (i + k < imgRows && j + l < imgCols) {
						sum += mask.at<float>(k, l) * input.at<uchar>(i + k, j + l);
					}
				}
			}
			output.at<float>(i, j) = sum;
		}
	}
	return output;
}

int main() {
	Mat src, grad;
	src = imread("lenna.jpg", IMREAD_COLOR);
	int scale = 1;
	int delta = 0;

	Mat grad_x, grad_y;
	Mat abs_grad_x, abs_grad_y;

	vector<Mat> src_planes;
	split(src, src_planes);

	// 블러링
	float weights[9] = { -1, -1, -1, -1, 9, -1, -1, -1, -1 };
	Mat mask = Mat(3, 3, CV_32F, weights);
	Mat result = userConolution(src, mask);

	// 소벨 에지
	Sobel(src, grad_x, CV_16S, 1, 0, 3, scale, delta, BORDER_DEFAULT);
	Sobel(src, grad_y, CV_16S, 0, 1, 3, scale, delta, BORDER_DEFAULT);

	convertScaleAbs(grad_x, abs_grad_x);
	convertScaleAbs(grad_y, abs_grad_y);
	addWeighted(abs_grad_x, 0.5, abs_grad_y, 0.5, 0, grad);

	imshow("Original", src);
	imshow("Bluring", result);
	imshow("Sebel Edge", grad);


	waitKey(0);
	return 0;
}