#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main() {
	/*
	Mat src = imread("C:/MICT/img/lenna.jpg", IMREAD_COLOR);
	Point2f srcTri[3];
	Point2f dstTri[3];
	Mat warp_mat(2, 3, CV_32FC1);

	Mat warp_dst;
	warp_dst = Mat::zeros(src.rows, src.cols, src.type());

	srcTri[0] = Point2f(0, 0);
	srcTri[1] = Point2f(src.cols - 1.0f, 0);
	srcTri[2] = Point2f(0, src.rows - 1.0f);

	// 마름모 모양으로 변형해보기
	dstTri[0] = Point2f(src.cols * 0.0f, src.rows * 0.33f);
	dstTri[1] = Point2f(src.cols * 0.77f, src.rows * 0.34f);
	dstTri[2] = Point2f(src.cols * 0.20f, src.rows * 0.7f);

	warp_mat = getAffineTransform(srcTri, dstTri);
	warpAffine(src, warp_dst, warp_mat, warp_dst.size());

	imshow("src", src);
	imshow("dst", warp_dst);
	*/

	// Code 7.11
	Mat src = imread("C:/MICT/img/lenna.jpg", IMREAD_GRAYSCALE);
	int rows = src.rows;
	int cols = src.cols;
	Mat dst = src.clone();
	Mat dst2 = src.clone();

	// 세로 방향 (교재)
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			int offset_x = (int)(25.0 * sin(2 * 3.14 * i / 180));
			int offset_y = 0;

			if (j + offset_x < rows)
				dst.at<uchar>(i, j) = src.at<uchar>(i, (j + offset_x) % cols);
			else {
				dst.at<uchar>(i, j) = 0;
			}
		}
	}

	// 가로 방향 -> 수정해보기
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			int offset_x = 0;
			int offset_y = (int)(25.0 * sin(2 * 3.14 * i / 180));
			
			if (i + offset_y < cols)
				dst2.at<uchar>(i, j) = src.at<uchar>((i + offset_y) % rows, j );
			else {
				dst2.at<uchar>(i, j) = 0;
			}
		}
	}

	//imshow("src", src);
	//imshow("가로 방향t", dst);
	imshow("세로 방향", dst2);

	waitKey(0);
	//return 0;
}