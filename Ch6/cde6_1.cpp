#include "opencv2/opencv.hpp"
#include <iostream>

using namespace std;
using namespace cv;


int main() { 
	Mat src = imread("C:/MICT/img/lenna.jpg", 1);

	/*
	// code 6.1 ����
	Mat dst(src.size(), CV_8UC3, Scalar(0, 0, 0));

	// (1, 1)���� (rows-1, cols-1) ������ ȭ�Ҹ� ó��
	for (int y = 1; y < src.rows - 1; y++) {
		for (int x = 1; x < src.cols - 1; x++) {
			for (int c = 0; c < 3; c++) {
				int sum = 0;
				sum += src.at<Vec3b>(y - 1, x - 1)[c];
				sum += src.at<Vec3b>(y, x - 1)[c];
				sum += src.at<Vec3b>(y + 1, x - 1)[c];
				sum += src.at<Vec3b>(y - 1, x)[c];
				sum += src.at<Vec3b>(y, x)[c];				// �߰���
				sum += src.at<Vec3b>(y + 1, x)[c];
				sum += src.at<Vec3b>(y - 1, x + 1)[c];
				sum += src.at<Vec3b>(y, x + 1)[c];
				sum += src.at<Vec3b>(y + 1, x + 1)[c];
				dst.at<Vec3b>(y, x)[c] = sum / 9;
			}
		}
	} */

	// code 6.3
	Mat dst;
	//blur(src, dst, Size(7, 7));		// ����ũ�� ��հ� ���͸� ����
	
	
	// code 6.4
	for (int i = 1; i < 31; i = i + 2) {			// Ȧ����
		GaussianBlur(src, dst, Size(i, i), 0, 0);	// ����þ� ������
		imshow("Gaussian filter", dst);
		waitKey(1000);
	} 
	
	/*
	imshow("initial", src);
	imshow("final", dst);
	waitKey(0);
	return 0;  */
}