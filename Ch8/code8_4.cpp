#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

// ����� ���� �Լ� : ħ��
Mat userErode(const Mat& src, Mat& element) {
    Mat dst(src.size(), CV_8U, Scalar(0));

    Point center = Point(element.cols / 2, element.rows / 2);

    for (int i = center.y; i < src.rows - center.y; ++i) {
        for (int j = center.x; j < src.cols - center.x; ++j) {
            Rect roiRect(j - center.x, i - center.y, element.cols, element.rows);
            Mat roi = src(roiRect);
            int minVal = 255;

            // ħ�� ���� 
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

// ����� ���� �Լ� : ��â
Mat userDialte(const Mat& src, Mat& element) {
    Mat dst(src.size(), CV_8U, Scalar(0));

    Point center = Point(element.cols / 2, element.rows / 2);

    for (int i = center.y; i < src.rows - center.y; ++i) {
        for (int j = center.x; j < src.cols - center.x; ++j) {
            Rect roiRect(j - center.x, i - center.y, element.cols, element.rows);
            Mat roi = src(roiRect);
            int maxVal = 0;

            // ��â ���� 
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
    Mat src, output;
    src = imread("C:/MICT/img/letterj.png", IMREAD_GRAYSCALE);
    
    // ������ ���¼�
    Mat element = (Mat_<uchar>(3, 3) << 0, 1, 0, 1, 1, 1, 0, 1, 0);

    // ����ȭ
    threshold(src, output, 128, 255, THRESH_BINARY);

    // ���� �߰�
    Mat slatpapper_noise = Mat::zeros(src.rows, src.cols, CV_8U);
    randu(slatpapper_noise, 0, 255);
   
    Mat black = slatpapper_noise < 30;
    Mat white = slatpapper_noise > 225;

    Mat slatpapper_img = output.clone();
    slatpapper_img.setTo(255, white);
    slatpapper_img.setTo(0, black);

    imshow("slatpapper_img", slatpapper_img);

    // open : ħ�� -> ��â
    Mat erosion_dst = userErode(slatpapper_img, element);
    Mat dilatition_dst = userDialte(erosion_dst, element);

    imshow("OPEN", dilatition_dst);

    // close : ��â -> ħ��
    Mat dilatition_dst1 = userDialte(slatpapper_img, element);
    Mat erosion_dst1 = userErode(dilatition_dst1, element);
    
    imshow("CLOSE", erosion_dst1);

    waitKey(0);
    return 0;
}
