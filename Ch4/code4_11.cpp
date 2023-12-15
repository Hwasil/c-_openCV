#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

void binaryToimage(Mat& dst, int value) { // 입력 영상, 임계값
	for (int r = 0; r < dst.rows; r++) {
		for (int c = 0; c < dst.cols; c++) {
			if (dst.at<uchar>(r,c) >= value) // 영상의 화소값과 임계값 비교
				dst.at<uchar>(r, c) = 255;
			else
				dst.at<uchar>(r, c) = 0;
		}
	}
	
}

int main() {
	Mat img = imread("C:/MICT/img/Lenna.jpg", IMREAD_GRAYSCALE);
	Mat dst = img.clone();
	int value;
	
	cout << "임계값 입력 >> "; 
	cin >> value;
	
	// 함수 호출
	binaryToimage(dst, value);

	imshow("Original", img);
	imshow("Binary", dst);

	waitKey(0);
	return 0;
}
