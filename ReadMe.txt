//Author : <Digant Desai><digantdesai@adsu.edu>
Files:
MySIFT.vcproj
    This is the main project file for VC++ projects generated using an Application Wizard.
    It contains information about the version of Visual C++ that generated the file, and
    information about the platforms, configurations, and project features selected with the
    Application Wizard.

SIFT.h
	This is the main project header file. It contains main 3 classes.
	-keypoint
	This is the keypoint object.It stores all keypoint related data.
	e.g.	x,y location;
		magnitude;
		orientation;
		scale;
	-descriptor
	This is the keypoint object.It stores all keypoint related data and Feature vectors
	e.g.	x,y location
		feature vector
		
	-SIFT
		This is the keypoint object.It stores all SIFT reladted data, functions.

main.cpp
	
	It has main function. Which do following tasks,
	1-Call SIFT for Object image,which will return its feature vector of (keypoints x 128).
	2-Call SUFT for Image.which will return its feature vector of (keypoints x 128)
	3-Flann using opencv FLANN library.(yet to be implemented fully)

SIFT.cpp
	Its the main implementation of the SIFT alforithm.
	Reference is from :JIFT by Jun Liu-http://www.cs.man.ac.uk/~liuja/#downloads

Comments:

More over I have added as much as possible comments on each phase.

Running instruction:

iTS A VISUAL STUDIO PROJECT.So,we can directly import it in visual studio and it will run smoothly.

Input Images:
Sample input images are stored in the folder.
And image file name should be mentioned in main.cpp.
here in main.cpp 
	filename_object="printer.png";
	filename_image="printer_real.png";

Output:

*****Processing Object*****
SIFT:Generating scale space...
SIFT:Detecting extrema...
SIFT:Found 310 keypoints
SIFT:Rejected 4289 keypoints
SIFT:Assigning orientations...
SIFT:Extract keypoint descriptors...
OBJECT:Feature Extraction time = 2469.56ms

*****Processing Object*****
SIFT:Generating scale space...
SIFT:Detecting extrema...
SIFT:Found 87 keypoints
SIFT:Rejected 2186 keypoints
SIFT:Assigning orientations...
SIFT:Extract keypoint descriptors...
IMAGE:Feature Extraction time = 2540.58ms

FLANN: not enabled





