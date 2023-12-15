// 202195027 오화실
#include "opencv2/opencv.hpp"
#include <iostream>

using namespace std;
using namespace cv;

Mat Convolution(Mat input, Mat mask) {
    Mat output;

    int imgRows = input.rows;
    int imgCols = input.cols;
    int maskRows = mask.rows;
    int maskCols = mask.cols;

    output = Mat::zeros(imgRows, imgCols, CV_32F); 

    // 컨볼루션 연산 수행
    for (int i = 0; i < imgRows; i++) {
        for (int j = 0; j < imgCols; j++) {
            // 마스크 입력영상에 적용
            float sum = 0.0;
            for (int k = 0; k < maskRows; k++) {
                for (int l = 0; l < maskCols; l++) {
                    if (i + k < imgRows && j + l < imgCols) {
                        sum += mask.at<float>(k, l) * input.at<uchar>(i + k, j + l);
                    }
                }
            }
            output.at<float>(i, j) = sum;
        }
    }
    return output;
}

int main() {
    Mat src = imread("C:/MICT/img/lenna.jpg", IMREAD_GRAYSCALE);

    float weights[9] = { -1, -1, -1, -1, 9, -1, -1, -1, -1 };   // 컨볼루션 커널 값
    // -1, -1, -1, -1, 9, -1, -1, -1, -1
    // 0, -1, 0, -1, 5, -1, 0, -1, 0
    // 1, -2, 1, -2, 5, -2, 1, -2, 1
    Mat mask = Mat(3, 3, CV_32F, weights);

    Mat result = Convolution(src, mask);

    Mat resultDisplay;
    result.convertTo(resultDisplay, CV_8U);                 // 8비트 부호없는 정수

    imshow("Original", src);
    imshow("Convolution", resultDisplay);

    waitKey(0);
    return 0;
}
