//snow fall
#include <iostream>
#include <math.h>
#include <opencv2/highgui/highgui.hpp>//to run it in visual studio replace'/'with'\\'
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>

using namespace cv;
using namespace std;

Mat frame;

int main()
{     
	int m,s[100],x[100],x1=0,y;
	namedWindow("snow_fall");//window to show the snow fall
	//namedWindow("canny");//window to show the canny eff(remove '//'to see the window)
	
	VideoCapture video(0);
	for(int i=0;i<100;i++)
	{
		x[i]=0;//initialize the position of snlow
		s[i]=rand() % 5; //create random sizes for the snlow circles(snow is represented as circles)
	}
    
    	while (1)
   	{
       		for(int i=0;i<100;i++) //to check if the snow goes out of the screen 
       		if(x[i]==frame.rows)
       		x[i]=0;
       		video >> frame;

       		Mat fi(frame.rows,frame.cols, CV_8UC3, 255)
       		   ,ca(frame.rows,frame.cols, CV_8UC3, 255);//stores the canny img
	
	

       		for(int i=0;i<frame.rows;i++)//loop to make mirror img
			for (int j = 0; j < frame.cols/2; j++)
    			{           		
				m=frame.at<Vec3b>(i, frame.cols-j)[0];
				frame.at<Vec3b>(i,frame.cols-j)[0]=frame.at<Vec3b>(i,j)[0];
				frame.at<Vec3b>(i,j)[0]=m;
				m=frame.at<Vec3b>(i, frame.cols-j)[1];
				frame.at<Vec3b>(i,frame.cols-j)[1]=frame.at<Vec3b>(i,j)[1];
				frame.at<Vec3b>(i,j)[1]=m;
				m=frame.at<Vec3b>(i, frame.cols-j)[2];
				frame.at<Vec3b>(i,frame.cols-j)[2]=frame.at<Vec3b>(i,j)[2];
				frame.at<Vec3b>(i,j)[2]=m;
   			}
   			
   		
   			for (int i=0;i<frame.rows;i++) //coppies the image from frame to other file with little modifiation in colour
        			for (int j=0;j<frame.cols;j++) 
        			{     
        			              
        				fi.at<Vec3b>(i,j)[0]=frame.at<Vec3b>(i,j)[0];
					fi.at<Vec3b>(i,j)[1]=(frame.at<Vec3b>(i,j)[1]*0.8);//done to reduce the warmth (increase blue colour )
					fi.at<Vec3b>(i,j)[2]=frame.at<Vec3b>(i,j)[2]*0.5;
    				}
    			Canny(frame,ca,100,150);	//used canny to make outline of the given image 
    			
    			
    			for(int i=0;i<frame.cols/10;i++)//loop to create snowfall 
    			{
    			circle(fi, Point(i*10,x[i]),s[i], Scalar(255,255,255),CV_FILLED, 8,0);                         //creats the snow
    			if(  ca.at<Vec3b>(i*10,x[i]+6)[0]<=200&&ca.at<Vec3b>(i*10,x[i]+6)[1]<=200&&ca.at<Vec3b>(i*10,x[i]+6)[2]<=200                //this checks the presence of black points below the snow(circle)
    			   &&ca.at<Vec3b>((i*10)+2,x[i]+6)[0]<=200&&ca.at<Vec3b>((i*10)+2,x[i]+6)[1]<=200&&ca.at<Vec3b>((i*10)+2,x[i]+6)[2]<=200
    			   &&ca.at<Vec3b>((i*10)+4,x[i]+6)[0]<=200&&ca.at<Vec3b>((i*10)+4,x[i]+6)[1]<=200&&ca.at<Vec3b>((i*10)+4,x[i]+6)[2]<=200
    			   &&ca.at<Vec3b>((i*10)-2,x[i]+6)[0]<=200&&ca.at<Vec3b>((i*10)-2,x[i]+6)[1]<=200&&ca.at<Vec3b>((i*10)-2,x[i]+6)[2]<=200)
    			{
    				x[i]=x[i]+3;
    			}
    			else if(x[i]==207)
    			x[i]=x[i]+3;                                             //to remove problem accured due to my webcam lens
    			
    			}
    			
    			
   			  			
		//imshow("canny",ca);
    		imshow("snow_fall", fi);
    		if (waitKey(33) == 27)
           	break;
    	}
}
//made by shourya shashank
//@deadshourya
