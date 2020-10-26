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

		int width = frame.size().width;
		int height = frame.size().height;

		imshow("live demo", frame);



		if (waitKey(30) >= 0) {
			break;
		}
	}

	return 0;
}