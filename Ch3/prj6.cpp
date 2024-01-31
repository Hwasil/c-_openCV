#define _CRT_SECURE_NO_WARNINGS
#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
using namespace std;

int main() {
	Mat img = imread("opencv.png", IMREAD_COLOR);
	if (img.empty()) { cout << "������ ���� �� ����" << endl;  return -1; }
	imshow("Original img", img);

	int stRow, endRow;
	cout << "���� �� = " << img.rows << endl;
	cout << "���� �� = " << img.cols << endl;
	cout << "����� ũ�� = " << img.size() << endl;

	cout << "�Է¹��� ó�� �� : ";
	cin >> stRow;
	
	cout << "�Է¹��� ������ �� : ";
	cin >> endRow;

	for (int r = stRow; r <= endRow; r++) {
		for (int j = 0; j < img.cols; ++j) {
			//cout << "�� : " << saturate_cast<uchar>(img.at<uchar>(r, j)) << endl;
			int b = img.at<Vec3b>(r, j)[0];
			int g = img.at<Vec3b>(r, j)[1];
			int r = img.at<Vec3b>(r, j)[2];
			cout << b << " " << g << " " << r << endl;
		}
		//cout << "�� ����" << endl; // ������
	}
	
	waitKey(0);
	return 0;
}