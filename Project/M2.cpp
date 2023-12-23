#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

Mat img, imgC;
Point stPoint, edPoint;
bool flags = false;

void onMouse(int event, int x, int y, int flags, void* param) {
	imgC = img.clone();

	if (event == EVENT_LBUTTONDOWN) {
		stPoint = Point(x, y);
		flags = true;
	}
	else if (event == EVENT_MOUSEMOVE && flags) {
		edPoint = Point(x, y);
		rectangle(imgC, stPoint, edPoint, Scalar(0, 0, 255), 1);
		imshow("img", imgC);
	}
	else if (event == EVENT_LBUTTONUP) {
		edPoint = Point(x, y);
		flags = false;

		Mat roi(imgC, Rect(stPoint, edPoint));

		for (int r = 0; r < roi.rows; r++) {
			uchar* p = roi.ptr<uchar>(r);
			for (int c = 0; c < roi.cols; c++) {
				p[c] = saturate_cast<uchar>(p[c] + 100);
			}
		}
		imshow("img", imgC);
	}
}

int main() {
	img = imread("Lenna.jpg");
	imgC = img.clone();

	imshow("img", imgC);

	setMouseCallback("img", onMouse, &img);

	waitKey(0);
	return 0;
}