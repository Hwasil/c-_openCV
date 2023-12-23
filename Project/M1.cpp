#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

bool flags = false;

void onMouse(int event, int x, int y, int flags, void* param) {
	if (event == EVENT_RBUTTONDOWN) {
		Mat& img = *(Mat*)(param);
		rectangle(img, Point(x, y), Point(x + 50, y + 50), Scalar(0, 0, 255), -1);
		imshow("img", img);
	}
	else if (event == EVENT_LBUTTONDOWN) {
		flags = true;
	}
	else if (event == EVENT_FLAG_LBUTTON && flags) {
		Mat& img = *(Mat*)(param);
		circle(img, Point(x, y), 3, Scalar(255, 255, 255), 10);
		imshow("img", img);
	}
}

int main() {
	Mat img = Mat(600, 800, CV_8UC3, Scalar(255, 255, 255));
	imshow("img", img);

	setMouseCallback("img", onMouse, &img);

	waitKey(0);
	return 0;
}