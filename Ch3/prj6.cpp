#define _CRT_SECURE_NO_WARNINGS
#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
using namespace std;

// 오류 코드
int main() {
	Mat img = imread("opencv.png", IMREAD_COLOR);
	if (img.empty()) { cout << "영상을 읽을 수 없음" << endl;  return -1; }
	imshow("Original img", img);

	int stRow, endRow;
	cout << "행의 수 = " << img.rows << endl;
	cout << "열의 수 = " << img.cols << endl;
	cout << "행렬의 크기 = " << img.size() << endl;

	cout << "입력받을 처음 행 : ";
	cin >> stRow;
	
	cout << "입력받을 마지막 행 : ";
	cin >> endRow;

	for (int r = stRow; r <= endRow; r++) {
		for (int j = 0; j < img.cols; ++j) {
			//cout << "행 : " << saturate_cast<uchar>(img.at<uchar>(r, j)) << endl;
			int b = img.at<Vec3b>(r, j)[0];
			int g = img.at<Vec3b>(r, j)[1];
			int r = img.at<Vec3b>(r, j)[2];
			cout << b << " " << g << " " << r << endl;
		}
		//cout << "행 종료" << endl; // 디버깅용
	}
	
	waitKey(0);
	return 0;
}
