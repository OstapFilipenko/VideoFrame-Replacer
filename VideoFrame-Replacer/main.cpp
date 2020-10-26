#include <opencv2/opencv.hpp>

using namespace cv;

int main() {
	VideoCapture cap(0);
	if (!cap.isOpened()) {
		return -1;
	}

	while (true) {
		Mat frame;
		cap >> frame;
		imshow("live demo", frame);
		if (waitKey(30) >= 0) {
			break;
		}
	}

	return 0;
}