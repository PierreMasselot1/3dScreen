#include <stdio.h>
#include <stdlib.h>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include "opencv2/imgproc.hpp"
#include "opencv2/objdetect.hpp"
#include <iostream>
#include <string.h>
#include "SerialPort.h"
#include <string>
#include <windows.h>
#include "Header.h"
 
 
 
#pragma comment (lib, "opencv_core343d.lib")
#pragma comment (lib, "opencv_highgui343d.lib")
#pragma comment (lib, "opencv_imgproc343d.lib")
#pragma comment (lib, "opencv_video343d.lib")
#pragma comment (lib, "opencv_imgproc343d.lib")
#pragma comment (lib, "opencv_imgcodecs343d.lib")
#pragma comment(lib, "opencv_objdetect343d.lib")
#pragma comment(lib,"opencv_videoio343d.lib")
 
 
#define DATA_LENGTH 10
 
using namespace cv;
using namespace std;
using std::cout;
using std::endl;
 
#define SEND
 
SerialPort *arduino;
int Arduino(int);
int xvalue;
int x;
int y;
char xx[] = "0";
char portName[] = "COM4";
char incomingData[DATA_LENGTH];

int main(int argc, char** argv)
{
   	
   	arduino = new SerialPort(portName);
 
   	VideoCapture cap(0);
   	cap.open(0);
   	Mat img;
 
   	CascadeClassifier face_cascade;
   	face_cascade.load("D:/opencv/build 3.4.3/install/etc/haarcascades/haarcascade_frontalface_alt2.xml");
   	
   	for (;;)
   	{
         	cap >> img;
         	cap.retrieve(img, CV_CAP_OPENNI_BGR_IMAGE);
         	resize(img, img, Size(1000, 640));
         	vector<Rect> faces;
 
         	face_cascade.detectMultiScale(img, faces, 1.1, 4, 64 | CV_HAAR_SCALE_IMAGE, Size(140, 140));
 
         	for (int i = 0; i < faces.size(); i++)
         	{
                	Point center(faces[i].x + faces[i].width*0.5, faces[i].y + faces[i].height*0.5);
                	ellipse(img, center, Size(faces[i].width*0.5, faces[i].height*0.5), 0, 0, 360, Scalar(0, 0, 255), 4, 8, 0);
 
                	x = faces[i].x - 320;
                	y = faces[i].y - 160;

         	}
 
         	if (faces.size() == 0) {
                	x = 0;
         	}
         	getx(x);
         	Arduino(x);
         	std::cout << xvalue<<"\n";
 
         	int key2 = waitKey(20);
         	imshow("facetracking", img);
   	}
   	return 0;
}
int Arduino(int x)
{
   	snprintf(xx,10, "%d", x);
   	if (arduino->isConnected()) {
         	bool hasWritten = arduino->writeSerialPort(xx, DATA_LENGTH);
   	}
   	return 0;


 

