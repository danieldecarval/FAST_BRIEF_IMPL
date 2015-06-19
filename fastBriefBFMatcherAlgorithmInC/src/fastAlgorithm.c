/*
 ============================================================================
 Name        : fastAlgorithm.c
 Author      : Daniel Fernandes
 Version     :
 Copyright   : Your copyright notice
 Description : FAST Algorithm in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "fast.h"
#include "brief.h"
#include <cv.h>
#include <highgui.h>
#include <math.h>

// Frame width and height of the capture
#define FRAME_WIDTH 640
#define FRAME_HEIGHT 480
// Maximum number of keypoint matches allowed by the program
#define MAXIMUM_NUMBER_OF_MATCHES 5000

int matchDescriptors(CvMat match1, CvMat match2,
		const int descs1[getNumberOfKeypoints()][DESC_LEN],
		const int descs2[getNumberOfKeypoints()][DESC_LEN],
		const CvPoint kpts1[getNumberOfKeypoints()],
		const CvPoint kpts2[getNumberOfKeypoints()], int nKpts1, int nKpts2);
void showMatches(const int matchCount);
void putImagesSideBySide(IplImage* result, const IplImage* img1,
		const IplImage* img2);
IplImage* applyTransformationsOnImage(IplImage* img);
void drawKeypoints(IplImage* img, xy* corners, int numOfKeypoints);
void convertXYToCvPoint(xy* corners, CvPoint tabKeypoints1[],
		int numKeypointsImg1);

/*
 * Get the different matches
 */
double match1Data[2 * MAXIMUM_NUMBER_OF_MATCHES];
double match2Data[2 * MAXIMUM_NUMBER_OF_MATCHES];

/*
 * Image to put side by side both images
 */
IplImage* sideBySideImage;

/*
 * Get the OpenCV Version
 */
void getOpenCvVersion() {
	puts(CV_VERSION);
}

/*
 * Start the timer for time computation
 */
double startTimer() {
	double t;
	t = (double) cvGetTickCount();
	return t;
}

/*
 * End the timer for time computation
 */
double endTimer(double t) {
	double ms;
	double t1;
	t1 = (double) cvGetTickCount() - t;
	ms = t1 / ((double) cvGetTickFrequency() * 1000.0);
	return ms;
}

/*
 * Apply different transformations (OPENCV) on image for the algorithms
 */
IplImage* applyTransformationsOnImage(IplImage* img) {
	IplImage* gray1 = cvCreateImage(cvSize(img->width, img->height),
	IPL_DEPTH_8U, 1);
	cvCvtColor(img, gray1, CV_RGB2GRAY);
	IplImage* img1resized = cvCreateImage(cvSize(FRAME_WIDTH, FRAME_HEIGHT),
	IPL_DEPTH_8U, 1);
	cvResize(gray1, img1resized, CV_INTER_LINEAR);
	cvReleaseImage(&gray1);
	return img1resized;
}

/*
 * Draw the keypoints on the image
 */
void drawKeypoints(IplImage* img, xy* corners, int numOfKeypoints) {
	int i;
	for (i = 0; i < numOfKeypoints; i++) {
		cvLine(img, cvPoint(corners[i].x - 1, corners[i].y),
				cvPoint(corners[i].x + 1, corners[i].y), CV_RGB(255, 0, 0), 2,
				8, 0);
		cvLine(img, cvPoint(corners[i].x, corners[i].y - 1),
				cvPoint(corners[i].x, corners[i].y + 1), CV_RGB(255, 0, 0), 2,
				8, 0);
	}
}

/*
 * Convert a xy structure to a CvPoint (OPENCV)
 */
void convertXYToCvPoint(xy* corners, CvPoint tabKeypoints[], int numOfKeypoints) {
	int i;
	for (i = 0; i < numOfKeypoints; i++) {
		tabKeypoints[i].x = corners[i].x;
		tabKeypoints[i].y = corners[i].y;
	}
}

/*
 * Match the descriptors of each keypoint
 */
int matchDescriptors(CvMat match1, CvMat match2,
		const int descs1[getNumberOfKeypoints()][DESC_LEN],
		const int descs2[getNumberOfKeypoints()][DESC_LEN],
		const CvPoint kpts1[getNumberOfKeypoints()],
		const CvPoint kpts2[getNumberOfKeypoints()], int nKpts1, int nKpts2) {
	static const int MAX_MATCH_DISTANCE = 50;
	int numberOfMatches = 0;
	int bestMatchInd2 = 0;

	unsigned int i, j;
	for (i = 0; i < nKpts1 && numberOfMatches < MAXIMUM_NUMBER_OF_MATCHES;
			i++) {
		int minDist = DESC_LEN;
		for (j = 0; j < nKpts2; j++) {
			const int dist = HAMMING_DISTANCE(descs1[i], descs2[j]);

			if (dist < minDist) {
				minDist = dist;
				bestMatchInd2 = j;
			}
		}
		if (minDist > MAX_MATCH_DISTANCE) {
			//continue;
		}

		const int xInd = 2 * numberOfMatches;
		const int yInd = xInd + 1;
		match1Data[xInd] = kpts1[i].x;
		match1Data[yInd] = kpts1[i].y;

		match2Data[xInd] = kpts2[bestMatchInd2].x;
		match2Data[yInd] = kpts2[bestMatchInd2].y;

		numberOfMatches++;
	}

	if (numberOfMatches > 0) {
		cvInitMatHeader(&match1, numberOfMatches, 2, CV_64FC1, match1Data,
		CV_AUTOSTEP);
		cvInitMatHeader(&match2, numberOfMatches, 2, CV_64FC1, match2Data,
		CV_AUTOSTEP);
	}
	return numberOfMatches;
}

/*
 * Draw the lines for the matchings
 */
void showMatches(const int matchCount) {
	const int iterationEnd = 2 * matchCount;

	int xCoor, yCoor;
	for (xCoor = 0, yCoor = 1; xCoor < iterationEnd; xCoor += 2, yCoor += 2) {
		cvLine(sideBySideImage, cvPoint(match1Data[xCoor], match1Data[yCoor]),
				cvPoint(match2Data[xCoor] + FRAME_WIDTH, match2Data[yCoor]),
				cvScalar(0, 255, 0, 0), 1, 8, 0);
	}
	cvShowImage("FinalImage", sideBySideImage);
	cvWaitKey(0);
}

/*
 * Put both images side by side in a bigger image
 */
void putImagesSideBySide(IplImage* result, const IplImage* img1,
		const IplImage* img2) {

	const int bigWS = result->widthStep;

	const int bigHalfWS = result->widthStep >> 1;

	const int lWS = img1->widthStep;

	const int rWS = img2->widthStep;

	char *p_big = result->imageData;

	char *p_bigMiddle = result->imageData + bigHalfWS;

	const char *p_l = img1->imageData;

	const char *p_r = img2->imageData;

	int i;

	for (i = 0; i < FRAME_HEIGHT; i++, p_big += bigWS, p_bigMiddle += bigWS) {
		memcpy(p_big, p_l + i * lWS, lWS);
		memcpy(p_bigMiddle, p_r + i * rWS, rWS);
	}

}

/*
 * Main function of the application
 */
int main(int argc, char* argv[]) {
	// Variables for timer
	double tStart1, tResult1, tResSom1, tStart2, tResult2, tResSom2;

	// Variables for the loop
	int i;

	// For the entry of the function from FAST, it needs an array of byte
	const char *dataImg1;
	const char *dataImg2;

	// Get the corners with the coordinates x and y --> the code from FAST provides this structure
	xy* corners1;
	xy* corners2;

	// Number of keypoints
	int numKeypointsImg1;
	int numKeypointsImg2;

	// Load the image to process
	IplImage* img1 = cvLoadImage("satellite.PNG", 1);
	IplImage* img2 = cvLoadImage("satellite.PNG", 1);

	if (img1 == NULL || img2 == NULL) {
		puts("ERROR, ONE OF YOUR IMAGE IS EMPTY ! ");
		return EXIT_FAILURE;
	}

	// Apply transormations on images for further work
	IplImage* img1resized = applyTransformationsOnImage(img1);
	IplImage* img2resized = applyTransformationsOnImage(img2);

	// Release the first and second initial image
	cvReleaseImage(&img1);
	cvRelease(&img2);

	// Copy the datas from the image to the byte array
	dataImg1 = (char *) img1resized->imageData;
	dataImg2 = (char *) img2resized->imageData;

//********************************* FAST ALGORITHM *********************************//

// Param for the threshold of FAST algorithm
	int b = 9;
	// Choose between fast_9, fast_10, fast_11 or fast_12
	int choice = 9;

	// Choose the version of FAST algorithm
	switch (choice) {
	// FAST 9
	case 9:
		tStart1 = startTimer();
		corners1 = fast9_detect_nonmax(dataImg1, img1resized->width,
				img1resized->height, img1resized->widthStep, b,
				&numKeypointsImg1);
		tResSom1 = endTimer(tStart1);
		tStart2 = startTimer();
		corners2 = fast9_detect_nonmax(dataImg2, img2resized->width,
				img2resized->height, img2resized->widthStep, b,
				&numKeypointsImg2);
		tResSom2 = endTimer(tStart2);
		break;
	case 10:
		tStart1 = startTimer();
		corners1 = fast10_detect_nonmax(dataImg1, img1resized->width,
				img1resized->height, img1resized->widthStep, b,
				&numKeypointsImg1);
		tResSom1 = endTimer(tStart1);
		break;
	case 11:
		tStart1 = startTimer();
		corners1 = fast11_detect_nonmax(dataImg1, img1resized->width,
				img1resized->height, img1resized->widthStep, b,
				&numKeypointsImg1);
		tResSom1 = endTimer(tStart1);
		break;
	case 12:
		tStart1 = startTimer();
		corners1 = fast12_detect_nonmax(dataImg1, img1resized->width,
				img1resized->height, img1resized->widthStep, b,
				&numKeypointsImg1);
		tResSom1 = endTimer(tStart1);
		break;
	default:
		printf("Error you choose a wrong number !");
		break;
	}
	printf("Timef is %lf ms for %d corners for the first image\n", tResSom1,
			numKeypointsImg1);
	printf("Timef is %lf ms for %d corners for the second image\n", tResSom2,
			numKeypointsImg2);

	// Draw the different keypoints (two lines to give an arrow)
	drawKeypoints(img1resized, corners1, numKeypointsImg1);
	drawKeypoints(img2resized, corners2, numKeypointsImg2);

	// Show the image with the keypoints
	cvShowImage("FAST_detection Image1", img1resized);
	cvShowImage("FAST_detection Image2", img2resized);
	// Wait the user to press a key to continue the program
	cvWaitKey(0);

//********************************* BRIEF ALGORITHM *********************************//

// The two descriptors arrays
	int desc1[numKeypointsImg1][DESC_LEN];
	int desc2[numKeypointsImg2][DESC_LEN];
	// The two arrays of keypoints
	CvPoint tabKeypoints1[numKeypointsImg1];
	CvPoint tabKeypoints2[numKeypointsImg2];

	// Convert xy structure to a CvPoint
	convertXYToCvPoint(corners1, tabKeypoints1, numKeypointsImg1);
	convertXYToCvPoint(corners2, tabKeypoints2, numKeypointsImg2);

//################ IMAGE 1 ################//
	// Initialize BRIEF algorithm constructor
	briefInit();
	// Set the number of Keypoints for the first image
	setNumberOfKeypoints(numKeypointsImg1);
	// Get the descriptors for the keypoints of the first image
	getBriefDescriptors(desc1, tabKeypoints1, img1resized);

//################ IMAGE 2 ################//
	// Set the number of Keypoints for the second image
	setNumberOfKeypoints(numKeypointsImg2);
	// Get the descriptors for the keypoints of the first image
	getBriefDescriptors2(desc2, tabKeypoints2, img2resized);
	// Call the BRIEF algorithm destructor
	briefDestroy();

//********************************* Brute Force Matcher ALGORITHM *********************************//

	// The two matrix for the matching
	CvMat match1;
	CvMat match2;

	// Call the function to match the descriptors for each keypoint
	int nbMatches = matchDescriptors(match1, match2, desc1, desc2,
			tabKeypoints1, tabKeypoints2, numKeypointsImg1, numKeypointsImg2);

	// Create a new image to put the images side by side (Image1|Image2)
	sideBySideImage = cvCreateImage(cvSize(FRAME_WIDTH * 2, FRAME_HEIGHT),
	IPL_DEPTH_8U, 1);

	// Call the function to put the images side by side (Image1|Image2)
	putImagesSideBySide(sideBySideImage, img1resized, img2resized);

	// Draw the matches in the sideBySideImage
	showMatches(nbMatches);

	// Liberate image from the memory
	cvReleaseImage(&img1resized);
	cvReleaseImage(&img2resized);

	printf("END OF PROGRAM \n");

	return EXIT_SUCCESS;

}

