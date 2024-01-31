#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
using namespace std;

// mouse event
void onMouse(int event, int x, int y, int flag, void* param) {
	if (event == EVENT_LBUTTONDOWN) {
		Mat& img = *(Mat*)(param);
		circle(img, Point(x, y), 100, Scalar(255, 0, 255), 3);
		imshow("src", img);
	}
	else if (event == EVENT_RBUTTONDOWN) {
		Mat& img = *(Mat*)(param);
		rectangle(img, Point(x, y), Point(x + 100, y + 100), Scalar(0, 255, 255), 5, LINE_AA);
		imshow("src", img);
	}
}

int main() {
	Mat src = Mat(600, 800, CV_8UC3, Scalar(102, 102, 102));
	if (src.empty()) { cout << "영상을 읽을 수 없음" << endl; }
	imshow("src", src);
	
	// mouse event
	setMouseCallback("src", onMouse, &src);
	waitKey(0);
	return 0;
}