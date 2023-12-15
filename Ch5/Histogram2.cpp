#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

using namespace cv;
using namespace std;

int low(Mat hist) {
    int min = 0;

    for (int i = 0; i < hist.rows; i++) {
        if (hist.at<float>(i) > 0) {
            min = i;
            break;
        }
    }

    return min;
}

int high(Mat hist) {
    int max = 255;

    for (int i = hist.rows - 1; i >= 0; i--) {
        if (hist.at<float>(i) > 0) {
            max = i;
            break;
        }
    }

    return max;
}
// code 5.4
// 히스토그램 스트레칭 함수 
Mat histo_stretch(Mat input) {
    Mat stImg = input.clone();

    // 영상의 누적 히스토그램
    Mat hist;
    int histSize = 256;
    float range[] = { 0, 256 };
    const float* histRange = { range };
    calcHist(&input, 1, 0, Mat(), hist, 1, &histSize, &histRange);

    // 화소값 최소, 최대 함수 호출
    int min = low(hist);
    int max = high(hist);

    // 새 화소값 공식
    for (int y = 0; y < input.rows; y++) {
        for (int x = 0; x < input.cols; x++) {
            int output = (input.at<uchar>(y, x) - min) * 255 / (max - min);
            stImg.at<uchar>(y, x) = saturate_cast<uchar>(output);
        }
    }

    return stImg;
}

int main() {
    Mat image = imread("C:/MICT/img/crayfish.jpg", IMREAD_GRAYSCALE);

    if (image.empty()) {
        cout << "이미지를 불러올 수 없습니다." << endl;
        return -1;
    }

    Mat resultImg = histo_stretch(image);

    imshow("Input", image);
    imshow("Output", resultImg);

    waitKey(0);
    return 0;
}