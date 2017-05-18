//barrel effect
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
	int w,v=100,m,x2,y2,pos;
	double ny, ny2,nx,nx2,r,theta,nxn,nyn,nr;  
	namedWindow("barrel effect");//window to show the barrel effect
	
	VideoCapture video(0);
    
    	while (1)
   	{
       		video >> frame;

       		Mat fi(frame.rows,frame.cols, CV_8UC3, 255);
	
	

       		for(int i=0;i<frame.rows;i++)//loop to make mirror img
			for (int j = 0; j < frame.cols/2; j++)
    			{           		
				m=frame.at<Vec3b>(i, frame.cols-j)[1];
				frame.at<Vec3b>(i,frame.cols-j)[1]=frame.at<Vec3b>(i,j)[1];
				frame.at<Vec3b>(i,j)[1]=m;
				m=frame.at<Vec3b>(i, frame.cols-j)[2];
				frame.at<Vec3b>(i,frame.cols-j)[2]=frame.at<Vec3b>(i,j)[2];
				frame.at<Vec3b>(i,j)[2]=m;
				m=frame.at<Vec3b>(i, frame.cols-j)[3];
				frame.at<Vec3b>(i,frame.cols-j)[3]=frame.at<Vec3b>(i,j)[3];
				frame.at<Vec3b>(i,j)[3]=m;
   			}
   			
   			
   			for (int y=0;y<frame.rows;y++) 
   			{
   			     	ny = (double)((2*(double)y)/(double)frame.rows)-1;   //y has been changed to double and modified to make it a unit value and usable in all four quadrant                     
        			ny2 = ny*ny;   
        			for (int x=0;x<frame.cols;x++) 
        			{                            
        				nx = (double)((2*(double)x)/(double)frame.cols)-1;                    
       				nx2 = nx*nx;
            			r = sqrt(nx2+ny2);// actual distance 
            			if (0.0<=r&&r<=1.0) //to remove unwanted value 1.41(root 2)
            			{                       
                				nr=r*(1-0.5*r*r);//new distance for the pixels from the center
                				theta = atan2(ny,nx);         
                    			nxn = nr*cos(theta);        //distributed to x and y axis
                    			nyn = nr*sin(theta);        
                    			x2 = (int)(((nxn+1)*frame.cols)/2.0);        //to rvert back to original value (which was changed above in nx and ny)
                    			y2 = (int)(((nyn+1)*frame.rows)/2.0);        
                        		fi.at<Vec3b>(y2,x2)[1]=frame.at<Vec3b>(y,x)[1];
                        		fi.at<Vec3b>(y2,x2)[2]=frame.at<Vec3b>(y,x)[2];
                     			fi.at<Vec3b>(y2,x2)[3]=frame.at<Vec3b>(y,x)[3];    
                    				
                				
            			}			
        			}
    			}
            	resize(fi, fi, Size(), 1.5, 1.5, INTER_LINEAR);//zoomed the image
            	for(int i=0;i<frame.rows;i++)//to remove unwanted borders
			for(int j=0;j<frame.cols;j++)
			{
				frame.at<Vec3b>(i,j)[1]=fi.at<Vec3b>(i+frame.rows/4,j+frame.cols/4)[1];
				frame.at<Vec3b>(i,j)[2]=fi.at<Vec3b>(i+frame.rows/4,j+frame.cols/4)[2];
				frame.at<Vec3b>(i,j)[3]=fi.at<Vec3b>(i+frame.rows/4,j+frame.cols/4)[3];
				
			}		
			
			
   			
   			  			
		
    		imshow("barrel effect", frame);
    		if (waitKey(33) == 27)
           	break;
    	}
}
//made by shourya shashank
//@deadshourya
