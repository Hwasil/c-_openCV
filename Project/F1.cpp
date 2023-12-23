#include "opencv2/opencv.hpp"
#include <iostream>

using namespace std;
using namespace cv;

/* 1. 
* BGR -> YUV
* 첫 번째 채널 평활화
* YUV -> BGR
* 출력 : 컬러영상(원본 or BRG로 바꾼 영상), 평활화 한 영상
*/

int main() {
	Mat src = imread("lenna.jpg", IMREAD_COLOR);
	
	Mat dst, imgYUV, redst;
	vector<Mat> yuv_planes;

	cvtColor(src, imgYUV, COLOR_BGR2YUV);
	split(imgYUV, yuv_planes);

	equalizeHist(yuv_planes[0], dst);	//  첫 번째 채널 평활화
	cvtColor(imgYUV, redst, COLOR_YUV2BGR);

	imshow("Original", src);
	imshow("imgYUV equlizeHist", dst);
	imshow("return BGR", redst);

	waitKey(0);
	return 0;
}