#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

// 히스토그램을 받아 막대그래프로 그리기
void drwaHist(int histogram[]) {
	int hist_w = 512;							// 히스토그램 영상의 폭
	int hist_h = 400;							// 히스토그램 영상의 높이
	int bin_w = cvRound((double)hist_w / 256);	// 빈의 폭
	int maxPixel;

	// 히스토그램이 그려지는 영상(컬러로 정의)
	Mat histImage(hist_h, hist_w, CV_8UC3, Scalar(255, 255, 255));

	// 히스토그램 최대값 찾기
	int max = histogram[0];
	for (int i = 1; i < 256; i++) {
		if (max < histogram[i]) {
			max = histogram[i];
			maxPixel = i;
		}
	}
	cout << endl << endl << "최대 개수 : " << max << endl;
	cout << "maxPixel = " << maxPixel << endl << endl;
	
	// 히스토그램 배열을 최대값으로 정규화(최대값이 최대 높이가 되도록)
	cout << "Normalize >> ";
	for (int i = 0; i < 256; i++) {
		histogram[i] = floor(((double)histogram[i] / max) * histImage.rows);
		cout << histogram[i] << ",";
	}
	
	// 히스토그램의 값을 빨간색 막대로 그리기
	for (int i = 0; i < 256; i++) {
		line(histImage, Point(bin_w * (i), hist_h), Point(bin_w * (i), hist_h - histogram[i]), Scalar(0, 0, 255));
	}
	imshow("Histogram", histImage);
}

int main() {
	Mat src = imread("C:/MICT/img/lenna.jpg", IMREAD_GRAYSCALE);
	imshow("Input Image", src);
	int histogram[256] = { 0 };

	for (int y = 0; y < src.rows; y++)
		for (int x = 0; x < src.cols; x++)
			histogram[(int)src.at<uchar>(y, x)]++;

	// Original Histogram
	cout << "Original >> ";
	for (int count : histogram)
		cout << count << "," ; 

	drwaHist(histogram);
	// 함수호출 후 위 코드 작성해도 정규화한 값 출력 가능

	waitKey(0);
	return 0;
}