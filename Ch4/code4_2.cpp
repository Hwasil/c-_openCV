#include "opencv2/opencv.hpp"

using namespace cv;
using namespace std;

// 포인터 사용
int main() {
	Mat img = imread("C:/MICT/img/lenna.jpg", IMREAD_GRAYSCALE);
	imshow("Original", img);

	/*
	for (int r = 0; r < img.rows; r++) {
		uchar* p = img.ptr<uchar>(r);  // r번째 행이 시작되는 주소
		for (int c = 0; c < img.cols; ++c) {
			p[c] = saturate_cast<uchar>(p[c] + 30);
		}
	} */

	if (img.isContinuous()) {  // 영상의 데이터 연속적 저장 검사
		uchar* p = img.data;
		for (int c = 0; c < img.cols * img.rows; c++) {
			*p++ = saturate_cast<uchar>(*p + 30);
		}
	}

	imshow("New", img);
	waitKey(0);
	return 0;
}
