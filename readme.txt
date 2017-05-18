These programme have been writen in c++ using opencv libraries

To run the programe
In terminal type  (linux) 

sudo apt-get install libopencv-dev //to install opncv

g++ -ggdb `pkg-config --cflags opencv` -o `basename <filename>.cpp .cpp` <filename>.cpp `pkg-config --libs opencv`  //to compile
./<filename>   //to run the programme



Project 1
Barrel effect

This programme creates barrel distortion effect to a webcam video feed. It uses a basic mathematical equation.

Algorithm-
  
	let x,y be any point in the image materix
	therefore its distance from the center will be equal to (x^2+y^2)^0.5 say r.
	now if we try to project that image on a sphere the the the distance between the center and the piont will change this canbe calculated as
		r'=r*(1-0.5*r^2)
	now taking r' as distance between the center and point the image is prepared
  
Compilation

	TYPE THESE IN TERMINAL-
		g++ -ggdb `pkg-config --cflags opencv` -o `basename barrel_effect.cpp .cpp` barrel_effect.cpp `pkg-config --libs opencv`
		
		./barrel_effect
		


PROJECT 2
OLD MOVIE

This programme creates monotonic old movie effect to a webcam video feed.

Algorithm-
	
	In this programme the coloured image is converted to sepia 
	first the image is converted to greyscale by adding all the values of RGB in aperfect ratio (for example concentration of green colour is highest beca use our eyes are evolved in a manner that they grasp the green tone more)
	then the the intensity of blue and green are reduced by a fraction to give the image yelloish shade.
	Then by using random function a random line and some circle are made to give the video an entique feel.
	
			
Compilation

	TYPE THESE IN TERMINAL-
		
		g++ -ggdb `pkg-config --cflags opencv` -o `basename old_movie.cpp .cpp` old_movie.cpp `pkg-config --libs opencv`
		
		./old_movie
	  
  	


PROJECT 3
SNOW FALL EFFECT

This programme creates a snow fall effect using canny edge detection

Algorithm
	In this preogramme snow is represented as white circles which moves verticaly through the frames of the video.
	the movement is controled by the canny edge detection the snow moves only when there is black colour bellow it in the canny image(ca)
	 
Compilation

	TYPE THESE IN TERMINAL-
	
		g++ -ggdb `pkg-config --cflags opencv` -o `basename snow_fall.cpp .cpp` snow_fall.cpp `pkg-config --libs opencv`
		
		./snow_fall
		


P.S.  the final build only supports mac and linux (to run in microsoft visual studio please make changes in the header files as shown in the comments in the programme )	  	 
//Created by Shourya Shashank
//@deadshourya 
