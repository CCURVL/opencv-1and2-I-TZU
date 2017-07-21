#include <opencv2/highgui/highgui.hpp>
#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int HW01_TestFunction();
int HW02_ReadAndShowData(int numberOfImgs);

vector <cv::Mat> Imgs;
vector <cv::Mat> ImgGrays;
vector <cv::Mat> ImgBinarys;


int main() {
	HW01_TestFunction();
	waitKey(0);
	destroyAllWindows();

	HW02_ReadAndShowData(8);

	waitKey(0);
	return 0;
}


int HW01_TestFunction() {

	// Fill your answer here
	Mat Imgs = imread("C:/Users/famil/Desktop/opencv-1and2-I-TZU/testImage/lena.jpg", CV_LOAD_IMAGE_UNCHANGED);
	Mat ImgGrays = imread("C:/Users/famil/Desktop/opencv-1and2-I-TZU/testImage/lena.jpg", CV_LOAD_IMAGE_GRAYSCALE);
	Mat ImgBinarys;

	imshow("one", Imgs);
	moveWindow("one", 0, 20);

	imshow("two", ImgGrays);
	moveWindow("two", 350, 20);

	threshold(ImgGrays, ImgBinarys, 150, 255, THRESH_BINARY);
	imshow("three", ImgBinarys);
	moveWindow("three", 700, 20);

	return 0;
}

int HW02_ReadAndShowData(int numberOfImgs) {
	// Fill your answer here
	vector<string>location;

	location.push_back("C:/Users/famil/Desktop/opencv-1and2-I-TZU/testImage/capture/1.jpg");
	location.push_back("C:/Users/famil/Desktop/opencv-1and2-I-TZU/testImage/capture/2.jpg");
	location.push_back("C:/Users/famil/Desktop/opencv-1and2-I-TZU/testImage/capture/3.jpg");
	location.push_back("C:/Users/famil/Desktop/opencv-1and2-I-TZU/testImage/capture/4.jpg");
	location.push_back("C:/Users/famil/Desktop/opencv-1and2-I-TZU/testImage/capture/5.jpg");
	location.push_back("C:/Users/famil/Desktop/opencv-1and2-I-TZU/testImage/capture/6.jpg");
	location.push_back("C:/Users/famil/Desktop/opencv-1and2-I-TZU/testImage/capture/7.jpg ");
	location.push_back("C:/Users/famil/Desktop/opencv-1and2-I-TZU/testImage/capture/8.jpg");

	int i,j;
	for (i = 0; i < numberOfImgs; i++) {
		Mat Imgs = imread(location[i], CV_LOAD_IMAGE_UNCHANGED);
		Mat ImgGrays = imread(location[i], CV_LOAD_IMAGE_GRAYSCALE);
		Mat ImgBinarys;

		imshow("one", Imgs);
		moveWindow("one", 0, 20);

		imshow("two", ImgGrays);
		moveWindow("two", 350, 20);

		threshold(ImgGrays, ImgBinarys, 150, 255, THRESH_BINARY);
		imshow("three", ImgBinarys);
		moveWindow("three", 700, 20);

		while (true) {
			char key = (char)cv::waitKey(0);
			if (key == 13) {
				destroyAllWindows();
				break;
			}
		}
	} 

	return 0;
}