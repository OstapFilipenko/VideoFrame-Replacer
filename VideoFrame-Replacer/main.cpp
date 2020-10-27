#include <opencv2/opencv.hpp>
#include<iostream>
#include <vector>

using namespace std;
using namespace cv;

int main() {
	VideoCapture cap(0);
	if (!cap.isOpened()) {
		return -1;
	}

	Mat frame;
	vector<Mat> tiles;


	while (true) {
		
		cap >> frame;

		int width = frame.size().width;
		int height = frame.size().height;
		int widthOfEachTile = width / 3;
		int heightOfEachTile = height / 3;
		

		for (int i = 1; i < 4; i++){
			for (int j = 1; j < 4; j++){
				tiles.push_back(frame(Rect(width/i, height/j, widthOfEachTile, heightOfEachTile)));
			}
		}


		
		tiles.at(3).copyTo(frame(Rect(0,0,widthOfEachTile, heightOfEachTile)));

		imshow("live demo", frame);



		if (waitKey(30) >= 0) {
			break;
		}
	}


	return 0;
}