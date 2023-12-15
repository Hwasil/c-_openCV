#include "opencv2/opencv.hpp"
using namespace cv;
using namespace std;

int main() {
	Mat LoadedImage = imread("Lenna.jpg", IMREAD_COLOR);
	imshow("Original", LoadedImage);
	cout << "Original ����� ũ�� = " << LoadedImage.size() << endl;

	resize(LoadedImage, LoadedImage, Size(300, 100));	// ����� ũ�� ����
	imwrite("resize.jpg", LoadedImage);
	imshow("New", LoadedImage);
	cout << "New ����� ũ�� = " << LoadedImage.size() << endl;

	waitKey();
	return 0;
}