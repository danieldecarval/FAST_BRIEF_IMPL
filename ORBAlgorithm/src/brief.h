/*
 * brief.h
 *
 * Created on: Jun 17, 2015
 * Author: dani
 */
#ifndef BRIEF_H_
#define BRIEF_H_
#include <stdlib.h>
#include <stdio.h>
#include <cv.h>
#include <highgui.h>
#include <math.h>
#include "utils.h"
typedef struct {
	xy point1;
	xy point2;
} pair;
// Initialize a type bool that is a char (other true or false)
typedef unsigned char bool;
#define true 1
#define false 0
// Length of the BRIEF descriptor:
#define DESC_LEN 256
// Size of the area in which the tests are computed:
#define PATCH_SIZE 37
// Box kernel size used for smoothing. Must be an odd positive integer:
#define KERNEL_SIZE 9
/***************************************************************************************************
 *
 * +++++++++++++++++++
 * +-a- | +
 * + b + a = IMAGE_PADDING_LEFT
 * + | + b = IMAGE_PADDING_TOP
 * + +++++++++++ + The area inside is the subimage we look for the keypoints such that
 * + + + + all the test locations we pick and the corners of the smoothing kernels
 * + + + + we apply to these test locations are guaranteed to be inside the image.
 * + + + + Note that in our implementation a = b
 * + + + +
 * + +++++++++++ +
 * + | -a-+
 * + b +
 * + | +
 * +++++++++++++++++++
 * Figure 1
 *
 **************************************************************************************************/
// See figure above:
int PATCH_SIZE_2();
int HALF_PATCH_SIZE();
int KERNEL_AREA();
int HALF_KERNEL_SIZE();
int IMAGE_PADDING_TOP();
int IMAGE_PADDING_LEFT();
int IMAGE_PADDING_TOTAL();
int IMAGE_PADDING_RIGHT();
int IMAGE_PADDING_BOTTOM();
int SUBIMAGE_LEFT();
int SUBIMAGE_TOP();
int HAMMING_DISTANCE(const char descs1[getNumberOfKeypoints()],
		const char descs2[getNumberOfKeypoints()]);
int SUBIMAGE_WIDTH(const int width);
int SUBIMAGE_HEIGHT(const int height);
int SUBIMAGE_RIGHT(const int width);
int SUBIMAGE_BOTTOM(const int height);
int GET_MATRIX_DATA(const int* pD, const int row, int column, const int wS);
// Returns the value of north-west corner of the kernel
int GET_PIXEL_NW(const int* pD, const xy point, const int wS);
int GET_PIXEL_NE(const int* pD, const xy point, const int wS);
int GET_PIXEL_SW(const int* pD, const xy point, const int wS);
int GET_PIXEL_SE(const int* pD, const xy point, const int wS);
xy POINT_PLUS(const xy p, const xy delta);
// Get the number of keypoints found by FAST algorithm
int getNumberOfKeypoints();
// Set the number of keypoints found by FAST algorithm
void setNumberOfKeypoints(int nKpts);
// The constructor only pre-computes the tests locations:
void briefInit();
// Destructor method:
void briefDestroy(void);
// Given keypoints kpts and image img, returns BRIEF descriptors descs for the first image
void getBriefDescriptors(char descriptors[getNumberOfKeypoints()][DESC_LEN],
		const xy kpts[getNumberOfKeypoints()], IplImage* img);
// Choose the test locations arbitrarily
void pickTestLocations(void);
// Checks if the tests locations for the keypoints in kpts lie inside an im_w x im_h image:
bool validateKeypoints(const xy kpts[getNumberOfKeypoints()], int im_w,
		int im_h);
// Returns true if kpt is inside the subimage
bool isKeypointInsideSubImage(const xy keypoint, const int width,
		const int height);
// Compute the integral of the image (Sum Area Table)
void computeIntegral(int width, int height, int matrix[height][width],
		int sat[height + 1][width + 1]);

// Will contain the locations randomly on the patch
pair testLocations[DESC_LEN];
// Number of keypoints
int numOfKeypoints;

#endif /* BRIEF_H_ */
