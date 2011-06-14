//Author : <Digant Desai><digantdesai@adsu.edu>
//main.cpp : Defines the entry point for the console application.
//CodeReference[1] JIFT by Jun Liu-http://www.cs.man.ac.uk/~liuja/#downloads
//Codereference [2] Andrea Vedaldi-http://www.vlfeat.org/~vedaldi/code/siftpp.html
#include <cv.h>
#include <highgui.h>
#include "stdafx.h"
#include "SIFT.h"

// The main function!
int main()
{
	// Create an instance of SIFT object and image
	char* filename_image = new char[200];
	char* filename_object = new char[200];
	filename_object="printer.png";
	filename_image="printer_real.png";


	//object**************************************************************************
	double tt1 = (double)cvGetTickCount();
	printf("\n*****Processing Object*****\n");
	CvMat* object_desc;
	CvSize object_size;
	SIFT *sift = new SIFT(filename_object, 4, 2);//object
	sift->DoSift();				// Find keypoints
	//sift->ShowAbsSigma();		// Display the sigma table
	sift->ShowKeypoints();		// Show the keypoints
#ifdef FLINN
	object_desc=sift->make_desc_mat();
	if(!object_desc)printf("error\n");
	object_size = cvGetSize( object_desc );
	printf("OBJECT:Keypoints=%d,Featurevector_length=%d\n",object_size.height,object_size.width);
#endif
	 tt1 = (double)cvGetTickCount() - tt1;
	 printf( "OBJECT:Feature Extraction time = %gms\n", tt1/(cvGetTickFrequency()*1000.));
	//Image**************************************************************************
	double tt2 = (double)cvGetTickCount();
	printf("\n*****Processing Object*****\n");
	CvMat* image_desc;
	CvSize image_size;
	SIFT *sift2 = new SIFT(filename_image, 4, 2);//image
	sift2->DoSift();				// Find keypoints
	sift2->ShowKeypoints();		// Show the keypoints
#ifdef FLINN
	image_desc=sift2->make_desc_mat();
	if(!image_desc)printf("error\n");
	image_size = cvGetSize(image_desc); 
	printf("IMAGE:Keypoints=%d,Featurevector_length=%d\n",image_size.height,image_size.width);
#endif.
	 tt2 = (double)cvGetTickCount() - tt2;
	 printf( "IMAGE:Feature Extraction time = %gms\n", tt2/(cvGetTickFrequency()*1000.));
	//FLINN**************************************************************************
#ifdef FLINN
	cv::Mat m_indices(image_size.height, 1, CV_32S);
    cv::Mat m_dists(image_size.height, 1, CV_32F);

    cv::flann::Index flann_index(object_desc, cv::flann::KDTreeIndexParams(4));  // using 4 randomized kdtrees

    flann_index.knnSearch(image_desc, m_indices, m_dists, 2, cv::flann::SearchParams(128) ); // maximum number of leafs checked

	// extracts A columns, 1 (inclusive) to 3 (exclusive).
	cv::Mat B = m_indices(cv::Range::all(), cv::Range::all());
	int* indices_ptr = m_indices.ptr<int>(0);
    float* dists_ptr = m_dists.ptr<float>(0);
	printf("value at %d is %d",indices_ptr-indices_ptr,*(indices_ptr));
	for(double d=0;d<25;d++){
	printf("value at %d is %d\n",(indices_ptr),*(indices_ptr));
	indices_ptr++;
	}
	
#endif

#ifndef FLANN
	printf("\nFLANN: not enabled\n");
#endif
	cvWaitKey(0);				// Wait for a keypress
	
	// Cleanup and exit
	delete sift;
	delete sift2;
	return 0;
}

