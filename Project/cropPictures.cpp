// 202195027 오화실
#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

Mat img, img_with_rectangle; // img_with_rectangle 사각형이 그려질 새로운 이미지
Point startPoint, endPoint;
bool cropping = false;  // 사각형 선택 중임을 나타내는 플래그 변수

// 마우스 이벤트 발생 시 호출되는 콜백 함수
void onMouse(int event, int x, int y, int flags, void* param) {
    img_with_rectangle = img.clone(); // 이미지 복사본
    if (event == EVENT_LBUTTONDOWN) {
        startPoint = Point(x, y);
        cropping = true;
    }
    else if (event == EVENT_MOUSEMOVE && cropping) {
        endPoint = Point(x, y);
        rectangle(img_with_rectangle, startPoint, endPoint, Scalar(255, 0, 0), 1);
        imshow("image", img_with_rectangle); // 드래그
    }
    else if (event == EVENT_LBUTTONUP) {
        endPoint = Point(x, y);
        cropping = false;
        rectangle(img_with_rectangle, startPoint, endPoint, Scalar(0, 255, 0), 1);
        imshow("image", img_with_rectangle); // 드래그로 그린 사각형
    }
}

int main() {
    img = imread("C:/MICT/img/Lenna.jpg", IMREAD_COLOR);
    img_with_rectangle = img.clone(); // 초기에 사각형이 그려지지 않은 원본 이미지 표시

    imshow("image", img_with_rectangle);

    setMouseCallback("image", onMouse); 

    while (1) {
        int key = waitKey(100);
        if (key == 'q') break;
        else if (key == 'c') { // 관심 영역 파일로 저장
            Mat roi = img(Rect(startPoint, endPoint));
            imwrite("result.jpg", roi);
        }
    }

    return 0;
}
