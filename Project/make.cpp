#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

// 사용자 정의 함수 : 침식
Mat userErode(const Mat& src, Mat& element) {
    Mat dst(src.size(), CV_8U, Scalar(0));

    Point center = Point(element.cols / 2, element.rows / 2);

    for (int i = center.y; i < src.rows - center.y; ++i) {
        for (int j = center.x; j < src.cols - center.x; ++j) {
            Rect roiRect(j - center.x, i - center.y, element.cols, element.rows);
            Mat roi = src(roiRect);
            int minVal = 255;

            // 침식 연산 
            for (int y = 0; y < element.rows; ++y) {
                for (int x = 0; x < element.cols; ++x) {
                    if (element.at<uchar>(y, x) != 0) {
                        minVal = min(minVal, static_cast<int>(roi.at<uchar>(y, x)));
                    }
                }
            }

            dst.at<uchar>(i, j) = minVal;
        }
    }

    return dst;
}

// 사용자 정의 함수 : 팽창
Mat userDialte(const Mat& src, Mat& element) {
    Mat dst(src.size(), CV_8U, Scalar(0));

    Point center = Point(element.cols / 2, element.rows / 2);

    for (int i = center.y; i < src.rows - center.y; ++i) {
        for (int j = center.x; j < src.cols - center.x; ++j) {
            Rect roiRect(j - center.x, i - center.y, element.cols, element.rows);
            Mat roi = src(roiRect);
            int maxVal = 0;

            // 팽창 연산 
            for (int y = 0; y < element.rows; ++y) {
                for (int x = 0; x < element.cols; ++x) {
                    if (element.at<uchar>(y, x) != 0) {
                        maxVal = max(maxVal, static_cast<int>(roi.at<uchar>(y, x)));
                    }
                }
            }

            dst.at<uchar>(i, j) = maxVal;
        }
    }

    return dst;
}

int main() {
    Mat src = imread("C:/MICT/img/morph.jpg", IMREAD_GRAYSCALE);

    // 십자형 형태소
    // Mat element = getStructuringElement(MORPH_CROSS, Size(3, 3), Point(-1, -1));
    Mat element = (Mat_<uchar>(3, 3) << 0, 1, 0, 1, 1, 1, 0, 1, 0);

    Mat erosion_dst = userErode(src, element);
    Mat dilatition_dst = userDialte(src, element);

    imshow("Original", src);
    imshow("erode", erosion_dst);
    imshow("dilate", dilatition_dst);

    waitKey(0);
    return 0;
}
