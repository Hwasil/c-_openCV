// 202195027 ��ȭ��
#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

Mat img, img_with_rectangle; // img_with_rectangle �簢���� �׷��� ���ο� �̹���
Point startPoint, endPoint;
bool cropping = false;  // �簢�� ���� ������ ��Ÿ���� �÷��� ����

// ���콺 �̺�Ʈ �߻� �� ȣ��Ǵ� �ݹ� �Լ�
void onMouse(int event, int x, int y, int flags, void* param) {
    img_with_rectangle = img.clone(); // �̹��� ���纻
    if (event == EVENT_LBUTTONDOWN) {
        startPoint = Point(x, y);
        cropping = true;
    }
    else if (event == EVENT_MOUSEMOVE && cropping) {
        endPoint = Point(x, y);
        rectangle(img_with_rectangle, startPoint, endPoint, Scalar(255, 0, 0), 1);
        imshow("image", img_with_rectangle); // �巡��
    }
    else if (event == EVENT_LBUTTONUP) {
        endPoint = Point(x, y);
        cropping = false;
        rectangle(img_with_rectangle, startPoint, endPoint, Scalar(0, 255, 0), 1);
        imshow("image", img_with_rectangle); // �巡�׷� �׸� �簢��
    }
}

int main() {
    img = imread("C:/MICT/img/Lenna.jpg", IMREAD_COLOR);
    img_with_rectangle = img.clone(); // �ʱ⿡ �簢���� �׷����� ���� ���� �̹��� ǥ��

    imshow("image", img_with_rectangle);

    setMouseCallback("image", onMouse); 

    while (1) {
        int key = waitKey(100);
        if (key == 'q') break;
        else if (key == 'c') { // ���� ���� ���Ϸ� ����
            Mat roi = img(Rect(startPoint, endPoint));
            imwrite("result.jpg", roi);
        }
    }

    return 0;
}