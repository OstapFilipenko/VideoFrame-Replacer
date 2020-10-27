#include <opencv2/opencv.hpp>
#include<iostream>

using namespace std;
using namespace cv;

int main() {
	VideoCapture cap(0);
	if (!cap.isOpened()) {
		return -1;
	}

	Mat frame;
	
	while (true) {
		
		cap >> frame;

		int width = frame.size().width;
		int height = frame.size().height;
		int widthOfEachTile = width / 3;
		int heightOfEachTile = height / 3;


		Mat firstTile = frame(Rect(0, 0, widthOfEachTile, heightOfEachTile));
		firstTile.copyTo(frame(Rect(widthOfEachTile, heightOfEachTile, widthOfEachTile, heightOfEachTile)));
		imshow("live demo", frame);



		if (waitKey(30) >= 0) {
			break;
		}
	}


	return 0;
}