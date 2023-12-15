#include "opencv2/opencv.hpp"

using namespace cv;

// code 6.8
Mat src, src_gray;
Mat dst, detected_edges;
int edgeThresh = 1;
int lowThreshold = 28;				//
int const max_lowThreshold = 100;	// »ó¼ö°ª
int ratio = 3;
int kernel_size = 3;

static void CannyThreshold(int, void*) {
	blur(src, detected_edges, Size(3, 3));
	Canny(detected_edges, detected_edges, lowThreshold, lowThreshold * ratio, kernel_size);
	dst = Scalar::all(0);
	src.copyTo(dst, detected_edges);
	imshow("Image", src);
	imshow("Canny", dst);
}

int main() {
	src = imread("C:/MICT/img/lenna.jpg", IMREAD_GRAYSCALE);

	dst.create(src.size(), src.type());
	
	CannyThreshold(0, 0);

	waitKey(0);
	return 0;
}