#define _CRT_SECURE_NO_WARNINGS
#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
using namespace std;

int main() {
	// p.92
	/*
	Mat A = imread("image2.jpg", IMREAD_COLOR);
	if (A.empty()) { cout << "������ ���� �� ����" << endl;  return -1; }
	Mat B = A;	// ���� ����
	imshow("Original img", A);

	flip(B, B, 0); // x�� ��Ī
	cout << "B�� �ݻ� ��Ŵ" << endl;
	imshow("img2_x", A);

	Mat F = A.clone();
	flip(F, F, 1); // y�� ��Ī
	imshow("img3_y", A);
	imshow("img3_F", F);

	Mat G;
	A.copyTo(G);
	flip(G, G, -1); // �����¿� ��Ī
	imshow("img4", A);
	imshow("img4_G", G);
	*/
	
	// p.95
	
	Mat M = Mat::eye(5, 10, CV_64F);	// 5 * 10�� �������, 64bit Float

	Mat Row = M.row(1);					// 1�� (index ��)
	cout << "Row = " << endl << Row << endl << endl;

	// ������ ��
	Mat Col = M.col(4);
	cout << "Col = " << endl << Col << endl << endl;

	// Ư���� �࿡�� Ư���� ������
	Mat E = M(Range::all(), Range(2, 4));	// 2������ 3������
	cout << "E = " << endl << E << endl << endl;
	

	waitKey(0);
	return 0;
}