#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
using namespace std;

int main() {
	Mat src = imread("Lenna.jpg"); //IMREAD_COLOR
	if (src.empty()) { cout << "영상을 읽을 수 없음" << endl;  return -1; }
	//imshow("src", src);

	Mat gray, dst;
	cvtColor(src, gray, COLOR_BGR2GRAY);

	//imshow("gray", gray);
	imwrite("gray.jpg", gray);

	Mat image = Mat(400, 600, CV_8UC3, Scalar(0, 0, 0));
	
	// Mat 객체 속성 p.74
	cout << "행의 수 = " << src.rows << endl;
	cout << "열의 수 = " << src.cols << endl;
	cout << "행렬의 크기 = " << src.size() << endl;
	cout << "전체 화소 개수= " << src.total() << endl;
	cout << "한 화소 크기 = " << src.elemSize() << endl;
	cout << "타입 = " << src.type() << endl;
	cout << "채널 = " << src.channels() << endl;	
	
	cout << "행의 수 = " << gray.rows << endl;
	cout << "열의 수 = " << gray.cols << endl;
	cout << "행렬의 크기 = " << gray.size() << endl;
	cout << "전체 화소 개수 = " << gray.total() << endl;
	cout << "한 화소 크기 = " << gray.elemSize() << endl;
	cout << "타입 = " << gray.type() << endl;
	cout << "채널 = " << gray.channels() << endl;
	
	imshow("Image", image);

	waitKey(0);
	return 0;
}