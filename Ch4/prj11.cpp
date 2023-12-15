#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;

int main() {
	Mat img = imread("C:/MICT/img/Lenna.jpg", IMREAD_GRAYSCALE);
	imshow("Original", img);

	for (int r = 0; r < img.rows; r++) {
		for (int c = 0; c < img.cols; ++c)
			img.at<uchar>(r, c) = saturate_cast<uchar>(img.at<uchar>(r, c) + 30);
	}							// 255이 넘는 값이면 255로 고정

	imshow("New", img);
	waitKey();
	return 0;
}