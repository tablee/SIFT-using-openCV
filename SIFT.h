//SIFT.h - holds classes for keypoint,keypoint descriptor , sift itself
//CodeReference[1] JIFT by Jun Liu-http://www.cs.man.ac.uk/~liuja/#downloads
//Codereference[2] Andrea Vedaldi-http://www.vlfeat.org/~vedaldi/code/siftpp.html

#include <cv.h>
#include <highgui.h>
#include <vector>
#include "stdafx.h"
//#define FLINN

using namespace std;
/*
*Holds keypoint
*/
class Keypoint
{
public:
	float			xi;
	float			yi;	// It's location
	vector<double>	mag;	// The list of magnitudes at this point
	vector<double>	orien;	// The list of orientations detected
	unsigned int	scale;	// The scale where this was detected

	Keypoint() { }
	Keypoint(float x, float y) { xi=x; yi=y; }
	Keypoint(float x, float y, vector<double> const& m, vector<double> const& o, unsigned int s)
	{
		xi = x;
		yi = y;
		mag = m;
		orien = o;
		scale = s;
	}
};
/*
*Holds keypoint Descriptor
*/
class Descriptor
{
public:
	float			xi, yi;		// The location
	vector<double>	fv;			// The feature vector

	Descriptor()
	{
	}

	Descriptor(float x, float y, vector<double> const& f)
	{
		xi = x;
		yi = y;
		fv = f;
	}
};
/*
*Class for SIFT
*/
class SIFT
{
public:
	SIFT(IplImage* img, int octaves, int intervals);
	SIFT(const char* filename, int octaves, int intervals);
	~SIFT();
	
	void DoSift();
	void ShowKeypoints();
	void ShowAbsSigma();
#ifdef FLINN	
	//FLINN patch, I know this is dirty 
	CvMat* make_desc_mat();
#endif
private:
	void GenerateLists();
	void BuildScaleSpace();
	void DetectExtrema();
	void AssignOrientations();
	void ExtractKeypointDescriptors();
	
	unsigned int GetKernelSize(double sigma, double cut_off=0.001);
	CvMat* BuildInterpolatedGaussianTable(unsigned int size, double sigma);
	double gaussian2D(double x, double y, double sigma);
	
private:
	IplImage* m_srcImage;			// The image we're working on
	unsigned int m_numOctaves;		// The desired number of octaves
	unsigned int m_numIntervals;	// The desired number of intervals
	unsigned int m_numKeypoints;	// The number of keypoints detected

	IplImage***	m_gList;		// A 2D array to hold the different gaussian blurred images
	IplImage*** m_dogList;		// A 2D array to hold the different DoG images
	IplImage*** m_extrema;		// A 2D array to hold binary images. In the binary image, 1 = extrema, 0 = not extrema
	double**	m_absSigma;		// A 2D array to hold the sigma used to blur a particular image
	//int  old_numKeypoint;
/*#ifdef FLINN	
*	CvMat* object_desc;
*	CvMat* image_desc;
*#endif
*/
	vector<Keypoint> m_keyPoints;	// Holds each keypoint's basic info
	vector<Descriptor> m_keyDescs;	// Holds each keypoint's descriptor
};

