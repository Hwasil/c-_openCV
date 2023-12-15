#include "opencv2/opencv.hpp"
#include <iostream>
using namespace std;
using namespace cv;

// code 5.2 + 5.3
void drawHist(int histogram[], Mat src) {
	vector<Mat> bgr_planes;		// 영상들의 벡터
	split(src, bgr_planes);		// 입력 영상 색상 별로 분리
	int histSize = 256;			// 히스토그램에서 사용되는 상자 개수
	float range[] = { 0, 256 };	// 화소값의 범위
	const float* histRange = { range };
	bool uniform = true, accumulate = false;
	Mat b_hist, g_hist, r_hist;

	// 각 플레인에 대한 히스토그램 계산
	calcHist(&bgr_planes[0], 1, 0, Mat(), b_hist, 1, &histSize, &histRange, uniform, accumulate);
	calcHist(&bgr_planes[1], 1, 0, Mat(), g_hist, 1, &histSize, &histRange, uniform, accumulate);
	calcHist(&bgr_planes[2], 1, 0, Mat(), r_hist, 1, &histSize, &histRange, uniform, accumulate);

	// 막대 그래프가 그려지는 영상 생성
	int hist_w = 512, hist_h = 400;
	int bin_w = cvRound((double)hist_w / histSize);	// 상자의 폭
	// (컬러로 정의)
	Mat histImage(hist_h, hist_w, CV_8UC3, Scalar(255, 255, 255));

	// 히스토그램 배열을 최대값으로 정규화
	normalize(b_hist, b_hist, 0, histImage.rows, NORM_MINMAX, -1, Mat());
	normalize(g_hist, g_hist, 0, histImage.rows, NORM_MINMAX, -1, Mat());
	normalize(r_hist, r_hist, 0, histImage.rows, NORM_MINMAX, -1, Mat());

	// 히스토그램 값을 막대로 그리기
	for (int i = 0; i < 255; i++) {
		line(histImage, Point(bin_w * (i), hist_h),
			Point(bin_w * (i), hist_h - b_hist.at<float>(i)), Scalar(255, 0, 0));
		line(histImage, Point(bin_w * (i), hist_h),
			Point(bin_w * (i), hist_h - g_hist.at<float>(i)), Scalar(0, 255, 0));
		line(histImage, Point(bin_w * (i), hist_h),
			Point(bin_w * (i), hist_h - r_hist.at<float>(i)), Scalar(0, 0, 255));
	}
	imshow("Color Histogram", histImage);
}

int main(int argc, char** argv) {
	Mat src = imread("C:/MICT/img/lenna.jpg", IMREAD_COLOR);
	imshow("Input", src);
	int histogram[256 * 3] = { 0 };
	
	// 각 색상 채널에 대한 히스토그램 계산
	for (int y = 0; y < src.rows; y++) {
		for (int x = 0; x < src.cols; x++) {
			for (int c = 0; c < 3; ++c) {
				histogram[c * 256 + static_cast<int>(src.at<Vec3b>(y, x)[c])]++;
			}
		}
	} 

	drawHist(histogram, src);
	waitKey(0);
	return 0;
}