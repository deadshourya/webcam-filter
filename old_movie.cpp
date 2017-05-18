//old movie effect
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
	int m,x,y;
	namedWindow("old movie");//window to show the old movie effect
	
	VideoCapture video(0);
    
    	while (1)
   	{
       		video >> frame;

       		Mat fi(frame.rows,frame.cols, CV_8UC3, 255);
	
	

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
   			
   		
   			for (int i=0;i<frame.rows;i++) // loop to give sepia colour filter to the image
        			for (int j=0;j<frame.cols;j++) 
        			{     
        			      //the sepia metrix used here has been derived from shotwell for perfection(modified a bit to increase warmth)                  
        				fi.at<Vec3b>(i,j)[0]=(0.272*frame.at<Vec3b>(i,j)[0]+0.534*frame.at<Vec3b>(i,j)[1]+0.131*frame.at<Vec3b>(i,j)[2])*0.7;
					fi.at<Vec3b>(i,j)[1]=(0.290*frame.at<Vec3b>(i,j)[0]+0.570*frame.at<Vec3b>(i,j)[1]+0.139*frame.at<Vec3b>(i,j)[2])*0.85;
					fi.at<Vec3b>(i,j)[2]=0.290*frame.at<Vec3b>(i,j)[0]+0.569*frame.at<Vec3b>(i,j)[1]+0.139*frame.at<Vec3b>(i,j)[2];
    				}
    				
    				//to create lines at random psition 
    				y=rand() % 5+ frame.cols/6;
    			for (int i=0;i<frame.rows;i++) 
    			{
    				
    				fi.at<Vec3b>(i,y)[0]=0;
    				fi.at<Vec3b>(i,y)[1]=0;
    				fi.at<Vec3b>(i,y)[2]=0;
    			}	
    			//to create random circles
    			y=rand() % frame.cols;
    			x=rand() % frame.rows;
    			m=rand() % 10;
    			circle(fi, Point(x,y),m, Scalar(255*0.7,255*0.85,255),CV_FILLED, 8,0);
    			y=rand() % frame.cols;
    			x=rand() % frame.rows;
    			m=rand() % 5;
    			circle(fi, Point(x,y),m, Scalar(255*0.5,255*0.85,255),CV_FILLED, 8,0);
    			y=rand() % frame.cols;
    			x=rand() % frame.rows;
    			m=rand() % 5;
    			circle(fi, Point(x,y),m, Scalar(0,0,0),CV_FILLED, 8,0);	
            	
          
   			
    		imshow("old movie", fi);
    		if (waitKey(33) == 27)
           	break;
    	}
}
//made by shourya shashank
//@deadshourya
