#include "opencv2/opencv.hpp"
#include <iostream>

using namespace std;
using namespace cv;

void displayDFT(Mat& src) {
	Mat image_array[2] = { Mat::zeros(src.size(), CV_32F), Mat::zeros(src.size(), CV_32F) };
	split(src, image_array);

	Mat mag_img;
	magnitude(image_array[0], image_array[1], mag_img);

	mag_img += Scalar::all(1);
	log(mag_img, mag_img);

	normalize(mag_img, mag_img, 0, 1, NORM_MINMAX);
	imshow("DFT", mag_img);
	waitKey(0);
}

void suffleDFT(Mat& src) {
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

Mat getFilter(Size size) {
	Mat filter = Mat::ones(size, CV_32FC2);
	circle(filter, size / 2, 10, Vec2f(0, 0), -1);
	return filter;
}

int main() {
	Mat src = imread("lenna.jpg", IMREAD_COLOR);
	Mat src_float;
	Mat dft_image;
	Mat result;

	src.convertTo(src_float, CV_32FC1, 1.0 / 255.0);
	dft(src_float, dft_image, DFT_COMPLEX_OUTPUT);
	suffleDFT(dft_image);
	displayDFT(dft_image);

	Mat pass = getFilter(dft_image.size());

	multiply(dft_image, pass, result);
	displayDFT(result);

	waitKey(0);
	return 1;
}