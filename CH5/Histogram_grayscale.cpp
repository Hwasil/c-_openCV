#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

// ������׷��� �޾� ����׷����� �׸���
void drwaHist(int histogram[]) {
	int hist_w = 512;							// ������׷� ������ ��
	int hist_h = 400;							// ������׷� ������ ����
	int bin_w = cvRound((double)hist_w / 256);	// ���� ��
	int maxPixel;

	// ������׷��� �׷����� ����(�÷��� ����)
	Mat histImage(hist_h, hist_w, CV_8UC3, Scalar(255, 255, 255));

	// ������׷� �ִ밪 ã��
	int max = histogram[0];
	for (int i = 1; i < 256; i++) {
		if (max < histogram[i]) {
			max = histogram[i];
			maxPixel = i;
		}
	}
	cout << endl << endl << "�ִ� ���� : " << max << endl;
	cout << "maxPixel = " << maxPixel << endl << endl;
	
	// ������׷� �迭�� �ִ밪���� ����ȭ(�ִ밪�� �ִ� ���̰� �ǵ���)
	cout << "Normalize >> ";
	for (int i = 0; i < 256; i++) {
		histogram[i] = floor(((double)histogram[i] / max) * histImage.rows);
		cout << histogram[i] << ",";
	}
	
	// ������׷��� ���� ������ ����� �׸���
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
	// �Լ�ȣ�� �� �� �ڵ� �ۼ��ص� ����ȭ�� �� ��� ����

	waitKey(0);
	return 0;
}