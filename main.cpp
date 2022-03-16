#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<opencv2/opencv.hpp>
#include<opencv2/core/core.hpp>
#include<iostream>
using namespace std;
using namespace cv;

int main( ){ 
	VideoCapture cap(0);
	cap.set(CAP_PROP_FRAME_WIDTH,640);
	cap.set(CAP_PROP_FRAME_HEIGHT,480);
	//cap.set(CAP_PROP_EXPOSURE,50);
	int rmin,gmin,bmin = 0;
	int rmax,gmax,bmax = 0;

	while(1){  
		Mat frame;
		cap >> frame;
		//imshow("frame",frame);

		Mat range;
		Mat gray;  
		Mat dstimage;
		frame.copyTo(range);
		frame.copyTo(dstimage);

		//imshow("range",range);
		createTrackbar("rmin","range",&rmin,255);
		createTrackbar("gmin","range",&gmin,255);	
		createTrackbar("bmin","range",&bmin,255);
		createTrackbar("rmax","range",&rmax,255);
		createTrackbar("gmax","range",&gmax,255);
		createTrackbar("bmax","range",&bmax,255);
		Mat test;
		Scalar low = cv::Scalar(bmin,gmin,rmin);
        Scalar high = cv::Scalar(bmax,gmax,rmax);
		//189,145,0
		//255,255,89
		//Exposure ||  100
		inRange(range,low,high,test);
		imshow("range",test);

		Rect roi_rect;
	    Rect roi_temp;
		vector<vector<Point>>contours;
		vector<Vec4i>hierarchy;
		vector<Rect> Rect_vector;
		int maxArea = 0;

        findContours(test,contours, hierarchy, cv::RETR_TREE, cv::CHAIN_APPROX_NONE);
	    for(std::vector<std::vector<cv::Point>>::iterator It = contours.begin(); It < contours.end(); It++)
	    {
	    	roi_temp = boundingRect(*(It));
	    	if (maxArea < roi_temp.area())
	    	{
	    		maxArea = roi_temp.area();
	    		roi_rect = roi_temp;
	    	}
	    }
	    rectangle(dstimage,roi_rect, cv::Scalar(0, 255, 0), 3);
        //this->roiRect = roi_rect;
	    imshow("dstImage",dstimage);
					
		
		waitKey(1);
		}
		  
return 0;     
}  