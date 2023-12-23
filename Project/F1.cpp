#include "opencv2/opencv.hpp"
#include <iostream>

using namespace std;
using namespace cv;

/* 1. 
* BGR -> YUV
* ù ��° ä�� ��Ȱȭ
* YUV -> BGR
* ��� : �÷�����(���� or BRG�� �ٲ� ����), ��Ȱȭ �� ����
*/

int main() {
	Mat src = imread("lenna.jpg", IMREAD_COLOR);
	
	Mat dst, imgYUV, redst;
	vector<Mat> yuv_planes;

	cvtColor(src, imgYUV, COLOR_BGR2YUV);
	split(imgYUV, yuv_planes);

	equalizeHist(yuv_planes[0], dst);	//  ù ��° ä�� ��Ȱȭ
	cvtColor(imgYUV, redst, COLOR_YUV2BGR);

	imshow("Original", src);
	imshow("imgYUV equlizeHist", dst);
	imshow("return BGR", redst);

	waitKey(0);
	return 0;
}