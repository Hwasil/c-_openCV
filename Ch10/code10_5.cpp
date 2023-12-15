#include "opencv2/opencv.hpp"
#include <iostream>

using namespace std;
using namespace cv;

void displayDFT(Mat& src) {
	Mat image_array[2] = { Mat::zeros(src.size(), CV_32F),  Mat::zeros(src.size(), CV_32F) };

	split(src, image_array);

	Mat mag_image;
	magnitude(image_array[0], image_array[1], mag_image);

	mag_image += Scalar::all(1);
	log(mag_image, mag_image);

	normalize(mag_image, mag_image, 0, 1, NORM_MINMAX);
	imshow("DFT", mag_image);
	waitKey(0);
}

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

// Code 10.5 저주파 원형 필터
Mat getLowFilter(Size size) {
	Mat filter(size, CV_32FC2, Vec2f(0, 0));
	circle(filter, size / 2, 50, Vec2f(1, 1), -1);
	return filter;
}

// Code 10.7 고주파 원형 필터
Mat getHighFilter(Size size) {
	Mat filter = Mat::ones(size, CV_32FC2);
	circle(filter, size / 2, 10, Vec2f(0, 0), -1);
	return filter;
}

// Code 10.8 수직 주파수 제거 필터
Mat getFilter(Size size) {
	Mat tmp = Mat(size, CV_32F);

	for (int i = 0; i < tmp.rows; i++) {
		for (int j = 0; j < tmp.cols; j++) {
			if (j > (tmp.cols / 2 - 10) && j < (tmp.cols / 2 + 10) && i > (tmp.rows / 2 + 10)) 
				tmp.at<float>(i, j) = 0;
			else if (j > (tmp.cols / 2 - 10) && j < (tmp.cols / 2 + 10) && i < (tmp.rows / 2 - 10)) 
				tmp.at<float>(i, j) = 0;
			else tmp.at<float>(i, j) = 1;
		}
	}

	Mat toMerge[] = { tmp, tmp };
	Mat filter;
	merge(toMerge, 2, filter);

	return filter;
}

int main() {
	// Mat src = imread("C:/MICT/img/lenna.jpg", IMREAD_GRAYSCALE);
	Mat src = imread("C:/MICT/img/lunar_alt2.jpg", IMREAD_GRAYSCALE);
	Mat src_float;
	Mat dft_image;
	imshow("Original", src);

	// 그래이스케일 영상(정수)을 실수 영상으로 변환
	src.convertTo(src_float, CV_32FC1, 1.0 / 255.0);
	dft(src_float, dft_image, DFT_COMPLEX_OUTPUT);
	shuffleDFT(dft_image);
	displayDFT(dft_image);

	// code 10.5
	// Mat lowpass = getLowFilter(dft_image.size());;

	// code 10.7
	// Mat lowpass = getHighFilter(dft_image.size());

	// code 10.8
	Mat lowpass = getFilter(dft_image.size());
	Mat result;

	// 원형 필터와 DFT 영상 곱하기
	multiply(dft_image, lowpass, result);
	displayDFT(result);

	Mat inverted_image;
	shuffleDFT(result);
	idft(result, inverted_image, DFT_SCALE | DFT_REAL_OUTPUT);
	imshow("inverted", inverted_image);
	
	waitKey(0);
	return 1;
}
