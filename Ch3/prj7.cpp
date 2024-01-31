#define _CRT_SECURE_NO_WARNINGS
#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
using namespace std;

int main() {
	// p.92
	/*
	Mat A = imread("image2.jpg", IMREAD_COLOR);
	if (A.empty()) { cout << "영상을 읽을 수 없음" << endl;  return -1; }
	Mat B = A;	// 얕은 복사
	imshow("Original img", A);

	flip(B, B, 0); // x축 대칭
	cout << "B만 반사 시킴" << endl;
	imshow("img2_x", A);

	Mat F = A.clone();
	flip(F, F, 1); // y축 대칭
	imshow("img3_y", A);
	imshow("img3_F", F);

	Mat G;
	A.copyTo(G);
	flip(G, G, -1); // 상하좌우 대칭
	imshow("img4", A);
	imshow("img4_G", G);
	*/
	
	// p.95
	
	Mat M = Mat::eye(5, 10, CV_64F);	// 5 * 10의 단위행렬, 64bit Float

	Mat Row = M.row(1);					// 1행 (index 값)
	cout << "Row = " << endl << Row << endl << endl;

	// 마지막 열
	Mat Col = M.col(4);
	cout << "Col = " << endl << Col << endl << endl;

	// 특정한 행에서 특정한 열까지
	Mat E = M(Range::all(), Range(2, 4));	// 2열에서 3열까지
	cout << "E = " << endl << E << endl << endl;
	

	waitKey(0);
	return 0;
}