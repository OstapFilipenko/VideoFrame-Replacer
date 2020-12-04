#include <opencv2/opencv.hpp>
#include<iostream>
#include <map>
#include <vector>

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

		
		cv::Mat shuffledVideo = cv::Mat::zeros(frame.rows, frame.cols, CV_8UC3);

		Mat tile1 = frame(Rect(0, 0, widthOfEachTile, heightOfEachTile));
		Mat tile2 = frame(Rect(0, heightOfEachTile, widthOfEachTile, heightOfEachTile));
		Mat tile3 = frame(Rect(0, heightOfEachTile*2, widthOfEachTile, heightOfEachTile));
		Mat tile4 = frame(Rect(widthOfEachTile, 0, widthOfEachTile, heightOfEachTile));
		Mat tile5 = frame(Rect(widthOfEachTile, heightOfEachTile, widthOfEachTile, heightOfEachTile));
		Mat tile6 = frame(Rect(widthOfEachTile, heightOfEachTile * 2, widthOfEachTile, heightOfEachTile));
		Mat tile7 = frame(Rect(widthOfEachTile*2, 0, widthOfEachTile, heightOfEachTile));
		Mat tile8 = frame(Rect(widthOfEachTile*2, heightOfEachTile, widthOfEachTile, heightOfEachTile));
		Mat tile9 = frame(Rect(widthOfEachTile*2, heightOfEachTile * 2, widthOfEachTile, heightOfEachTile));


		tile1.copyTo(shuffledVideo(Rect(widthOfEachTile * 2, heightOfEachTile * 2, widthOfEachTile, heightOfEachTile)));
		tile9.copyTo(shuffledVideo(Rect(0, 0, widthOfEachTile, heightOfEachTile)));
		tile8.copyTo(shuffledVideo(Rect(widthOfEachTile * 2, 0, widthOfEachTile, heightOfEachTile)));
		tile5.copyTo(shuffledVideo(Rect(widthOfEachTile, heightOfEachTile * 2, widthOfEachTile, heightOfEachTile)));
		tile7.copyTo(shuffledVideo(Rect(0, heightOfEachTile, widthOfEachTile, heightOfEachTile)));
		tile6.copyTo(shuffledVideo(Rect(0, heightOfEachTile * 2, widthOfEachTile, heightOfEachTile)));
		tile2.copyTo(shuffledVideo(Rect(widthOfEachTile * 2, heightOfEachTile, widthOfEachTile, heightOfEachTile)));
		tile3.copyTo(shuffledVideo(Rect(widthOfEachTile, 0, widthOfEachTile, heightOfEachTile)));
		tile4.copyTo(shuffledVideo(Rect(widthOfEachTile, heightOfEachTile, widthOfEachTile, heightOfEachTile)));

		

		imshow("live demo", frame);
		imshow("shuffeld Video", shuffledVideo);


		if (waitKey(30) >= 0) {
			break;
		}
	}


	return 0;
}