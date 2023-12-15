#include "opencv2/opencv.hpp"
#include <iostream>

using namespace std;
using namespace cv;

int main() {
	/*
	// Code 6.5 ������
	Mat src = imread("C:/MICT/img/lenna.jpg", IMREAD_COLOR);

	Mat dst, dst1, dst2;
	float weights[9] = { -1, -1, -1, -1, 9, -1, -1, -1, -1 };		// ����ũ��
	float weights1[9] = { 0, -1, 0, -1, 5, -1, 0, -1, 0 };
	float weights2[9] = { 1, -2, 1, -2, 5, -2, 1, -2, 1 };

	Mat mask = Mat(3, 3, CV_32F, weights);
	Mat mask1 = Mat(3, 3, CV_32F, weights1);
	Mat mask2 = Mat(3, 3, CV_32F, weights2);

	filter2D(src, dst, -1, mask, Point(-1, -1), 0, BORDER_DEFAULT);	// ������ ���͸� ����
	filter2D(src, dst1, -1, mask1, Point(-1, -1), 0, BORDER_DEFAULT);
	filter2D(src, dst2, -1, mask2, Point(-1, -1), 0, BORDER_DEFAULT);

	imshow("Original", src);
	imshow("sharpen", dst);
	imshow("sharpen1", dst1);
	imshow("sharpen2", dst2);
	
	
	// code 6.6 1�� �̺� ����
	Mat src;
	Mat grad;
	int scale = 1;
	int delta = 0;
	src = imread("C:/MICT/img/lenna.jpg", IMREAD_GRAYSCALE);

	Mat grad_x, grad_y;
	Mat abs_grad_x, abs_grad_y;
	
	// x ����� y �������� �̺а� ���
	Sobel(src, grad_x, CV_16S, 1, 0, 3, scale, delta, BORDER_DEFAULT);
	Sobel(src, grad_y, CV_16S, 0, 1, 3, scale, delta, BORDER_DEFAULT);
	
	convertScaleAbs(grad_x, abs_grad_x);					// CV_8U �������� ��ȯ
	convertScaleAbs(grad_y, abs_grad_y);
	addWeighted(abs_grad_x, 0.5, abs_grad_y, 0.5, 0, grad);	// 2���� ����� ����ġ �� ���

	imshow("Original", src);
	imshow("Sobel", grad);
	imshow("X-axis edge", abs_grad_x);	// x�� ���� ���
	imshow("Y-axis edge", abs_grad_y);	// y�� ���� ���
	*/
	
	// code 6.7 2�� �̺� ����
	// �߰� ���� ��� �ȳ�
	Mat src, src_gray, dst;
	int kernel_size = 3;
	int scale = 1;
	int delta = 0;
	int ddepth = CV_16S;
	src = imread("C:/MICT/img/lenna.jpg", IMREAD_GRAYSCALE);

	GaussianBlur(src, src, Size(3, 3), 0, 0, BORDER_DEFAULT);				// ���� ���� (�����)
	Mat abs_dst;
	Laplacian(src, dst, ddepth, kernel_size, scale, delta, BORDER_DEFAULT);	// ���ö�þ�
	convertScaleAbs(dst, abs_dst);											// CV_8U �������� ��ȯ
	
	imshow("Original", src);
	imshow("Laplacian", abs_dst);
	
	waitKey(0);
	return 0;
}
