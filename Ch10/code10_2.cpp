#include "opencv2/opencv.hpp"
#include <iostream>

using namespace std;
using namespace cv;
// 주석 작성하기
// code 10.2
void displayDFT(Mat& src) {
	Mat image_array[2] = { Mat::zeros(src.size(), CV_32F),  Mat::zeros(src.size(), CV_32F) };

	// 
	split(src, image_array);

	Mat mag_image;
	//
	magnitude(image_array[0], image_array[1], mag_image);

	mag_image += Scalar::all(1);
	log(mag_image, mag_image);

	normalize(mag_image, mag_image, 0, 1, NORM_MINMAX);
	imshow("DFT", mag_image);
	waitKey(0);
}

// code 10.3
void shuffleDFT(Mat& src) {
	int cX = src.cols / 2;
	int cY = src.rows / 2;

	Mat q1(src, Rect(0, 0, cX, cY));
	Mat q2(src, Rect(cX, 0, cX, cY));
	Mat q3(src, Rect(0, cY, cX, cY));
	Mat q4(src, Rect(cX, cY, cX, cY));

	Mat temp;
	q1.copyTo(temp);
	q4.copyTo(q1);
	temp.copyTo(q4);
	q2.copyTo(temp);
	q3.copyTo(q2);
	temp.copyTo(q3);
}

int main() {
	Mat src = imread("C:/MICT/img/beach.png", IMREAD_GRAYSCALE);
	Mat src_float;
	Mat dft_image;

	imshow("Original", src);

	// 그래이스케일 영상(정수)을 실수 영상으로 변환
	src.convertTo(src_float, CV_32FC1, 1.0 / 255.0);

	dft(src_float, dft_image, DFT_COMPLEX_OUTPUT);
	shuffleDFT(dft_image);
	displayDFT(dft_image);
	
	return 1;
}
