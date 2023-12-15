#include "opencv2/opencv.hpp"
#include <stdlib.h>
#include <stdio.h>

using namespace cv;
// 실행 오류 -> 수정 필요

Mat src, src_gray, dst;
//int threshold_value = 0;
//int threshold_type = 0;

void Threshold_Demo(int threshold_value, int threshold_type,  void*) { // 트랙바 변경 시 함수 호출
	threshold(src_gray, dst, threshold_value, 255, threshold_type);
	imshow("결과 영상", dst);
}

int main() {
	int threshold_value = 0;
	int threshold_type = 0;

	src = imread("C:/MICT/img/Lenna.jpg");
	cvtColor(src, src_gray, COLOR_BGR2GRAY);
	namedWindow("결과 영상", WINDOW_AUTOSIZE);

	// 트랙바 생성, 콜백 함수와 연결
	createTrackbar("임계값", "결과 영상", &threshold_value, 255, Threshold_Demo); 
	

	//Threshold_Demo(0, 0);

	while (1) {
		int c;
		c = waitKey(0);
		if ((char)c == 27) {
			break;
		}
	}

	return 0;
}
