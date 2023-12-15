#include "opencv2/opencv.hpp"
using namespace cv;
using namespace std;

int main() {
	Mat LoadedImage = imread("Lenna.jpg", IMREAD_COLOR);
	imshow("Original", LoadedImage);
	cout << "Original 행렬의 크기 = " << LoadedImage.size() << endl;

	resize(LoadedImage, LoadedImage, Size(300, 100));	// 행렬의 크기 변경
	imwrite("resize.jpg", LoadedImage);
	imshow("New", LoadedImage);
	cout << "New 행렬의 크기 = " << LoadedImage.size() << endl;

	waitKey();
	return 0;
}