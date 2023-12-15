#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

// code 5.5
Mat equalizeHist(Mat src) {
	// ������ ���� ������׷�
	Mat hist;
	int histSize = 256;
	float range[] = { 0, 256 };
	const float* histRange = { range };
	calcHist(&src, 1, 0, Mat(), hist, 1, &histSize, &histRange);

	// ���� ������׷� ���� 0-1 ���̷� ����ȭ
	for (int i = 1; i < hist.rows; i++) {
		hist.at<float>(i) += hist.at<float>(i - 1);
	}
	hist /= src.total();

	// ����ȭ�� ���� ������׷��� ��ȯ �Լ��� �̿��Ͽ� ȭ�Ұ��� ��ȯ
	Mat dst = src.clone();
	for (int y = 0; y < src.rows; y++) {
		for (int x = 0; x < src.cols; x++) {
			dst.at<uchar>(y, x) = saturate_cast<uchar>(255 * hist.at<float>(src.at<uchar>(y, x)));
		}
	}

	return dst;
}

int main() {
	Mat src = imread("C:/MICT/img/crayfish.jpg", IMREAD_GRAYSCALE);
	if (src.empty()) { return -1; };

	Mat dst = equalizeHist(src);

	imshow("Input", src);
	imshow("result", dst);

	waitKey(0);
	return 0;
}