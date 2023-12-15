#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main() {
	Mat img = imread("C:/MICT/img/Lenna.jpg", IMREAD_COLOR);
	cout << "영상 크기 : " << img.rows << "x" << img.cols << endl << endl;

	if (img.isContinuous())
		img.reshape(1, img.cols * img.rows);
	imshow("reshape img", img);
	   
	waitKey();
	return 0;
}
