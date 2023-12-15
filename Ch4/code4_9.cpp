#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

int contrasEnh(int input, int x1, int y1, int x2, int y2) {
	double output;

	if (0 <= input && input <= x1) {
		output = y1 / x1 * input;
	}
	else if (x1 < input && input <= x2) {
		output = ((y2 - y1) / (x2 - x1)) * (input - x1) + y1;
	}
	else if (x2 < input && input <= 255) {
		output = ((255 - y2) / (255 - x2)) * (input - x2) + y2;
	}
	return (int)output;
}

int main() {
	Mat image = imread("C:/MICT/img/lenna.jpg"); //, IMREAD_GRAYSCALE
	Mat oimage = image.clone();

	int x1, y1, x2, y2;
	cout << "x1 값 입력 >> "; cin >> x1;
	cout << "y1 값 입력 >> "; cin >> y1;
	cout << "x2 값 입력 >> "; cin >> x2;
	cout << "y2 값 입력 >> "; cin >> y2;

	for (int r = 0; r < image.rows; r++) {
		for (int c = 0; c < image.cols; c++) {
			for (int ch = 0; ch < 3; ch++) {
				int output = contrasEnh(image.at<Vec3b>(r, c)[ch], x1, y1, x2, y2);
				oimage.at<Vec3b>(r, c)[ch] = saturate_cast<uchar>(output);
			}
		}
	}
	imshow("Original", image);
	imshow("Result", oimage);

	waitKey();
	return 0;
}
