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
// ������׷� ��Ʈ��Ī �Լ� 
Mat histo_stretch(Mat input) {
    Mat stImg = input.clone();

    // ������ ���� ������׷�
    Mat hist;
    int histSize = 256;
    float range[] = { 0, 256 };
    const float* histRange = { range };
    calcHist(&input, 1, 0, Mat(), hist, 1, &histSize, &histRange);

    // ȭ�Ұ� �ּ�, �ִ� �Լ� ȣ��
    int min = low(hist);
    int max = high(hist);

    // �� ȭ�Ұ� ����
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
        cout << "�̹����� �ҷ��� �� �����ϴ�." << endl;
        return -1;
    }

    Mat resultImg = histo_stretch(image);

    imshow("Input", image);
    imshow("Output", resultImg);

    waitKey(0);
    return 0;
}