#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

// code 2.2
int main()
{
	Mat image; // 비어있는 Mat 객체(영상 데이터 표현)
	image = imread("C:/MICT/img/lenna.jpg", IMREAD_COLOR); // 지정된 영상 메모리에 적재
	if (image.empty()) { cout << "영상을 읽을 수 없음" << endl; }

	imshow("출력 영상", image);
	waitKey(0);	// 사용자가 키를 누를 때까지 대기 (msec, 0 : 계속 대기)
	return 0;
}
