#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
using namespace std;

int main() {
	Mat src = imread("Lenna.jpg"); //IMREAD_COLOR
	if (src.empty()) { cout << "������ ���� �� ����" << endl;  return -1; }
	//imshow("src", src);

	Mat gray, dst;
	cvtColor(src, gray, COLOR_BGR2GRAY);

	//imshow("gray", gray);
	imwrite("gray.jpg", gray);

	Mat image = Mat(400, 600, CV_8UC3, Scalar(0, 0, 0));
	
	// Mat ��ü �Ӽ� p.74
	cout << "���� �� = " << src.rows << endl;
	cout << "���� �� = " << src.cols << endl;
	cout << "����� ũ�� = " << src.size() << endl;
	cout << "��ü ȭ�� ����= " << src.total() << endl;
	cout << "�� ȭ�� ũ�� = " << src.elemSize() << endl;
	cout << "Ÿ�� = " << src.type() << endl;
	cout << "ä�� = " << src.channels() << endl;	
	
	cout << "���� �� = " << gray.rows << endl;
	cout << "���� �� = " << gray.cols << endl;
	cout << "����� ũ�� = " << gray.size() << endl;
	cout << "��ü ȭ�� ���� = " << gray.total() << endl;
	cout << "�� ȭ�� ũ�� = " << gray.elemSize() << endl;
	cout << "Ÿ�� = " << gray.type() << endl;
	cout << "ä�� = " << gray.channels() << endl;
	
	imshow("Image", image);

	waitKey(0);
	return 0;
}