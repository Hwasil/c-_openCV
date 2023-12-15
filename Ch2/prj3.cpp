#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv; 
using namespace std;

// mouse event
void onMouse(int event, int x, int y, int flag, void* param) {
	if (event == EVENT_LBUTTONDOWN) {
		Mat& img = *(Mat*)(param);
		circle(img, Point(x, y), 100, Scalar(0, 255, 0), 10);
		putText(img, "I found a dog!", Point(x - 300, y), FONT_HERSHEY_TRIPLEX, 1.0, 100, 2);
		imshow("src", img);
	}
}

int main() {
	Mat src = imread("dog.jpg", IMREAD_COLOR);
	if (src.empty()) { cout << "영상을 읽을 수 없음" << endl; }
	imshow("src", src);

	setMouseCallback("src", onMouse, &src);

	waitKey(0);
	return 0;

	// key board event 코드만 읽음
}