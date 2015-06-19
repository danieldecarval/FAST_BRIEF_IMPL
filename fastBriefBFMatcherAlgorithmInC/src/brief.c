/*
 * brief.c
 *
 *  Created on: Jun 17, 2015
 *      Author: dani
 */

#include "brief.h"

// Size of the area surrounding feature point
int PATCH_SIZE_2() {
	return PATCH_SIZE * PATCH_SIZE;
}
// Half of the patch size
int HALF_PATCH_SIZE() {
	return PATCH_SIZE >> 1;
}
// Area of the smoothing kernel
int KERNEL_AREA() {
	return KERNEL_SIZE * KERNEL_SIZE;
}
// Half of the kernel size
int HALF_KERNEL_SIZE() {
	return KERNEL_SIZE >> 1;
}

int IMAGE_PADDING_TOP() {
	return HALF_KERNEL_SIZE() + HALF_PATCH_SIZE();
}

int IMAGE_PADDING_LEFT() {
	return IMAGE_PADDING_TOP();
}

int IMAGE_PADDING_TOTAL() {
	return IMAGE_PADDING_TOP() << 1;
}

int IMAGE_PADDING_RIGHT() {
	return IMAGE_PADDING_LEFT();
}

int IMAGE_PADDING_BOTTOM() {
	return IMAGE_PADDING_TOP();
}

int SUBIMAGE_LEFT() {
	return IMAGE_PADDING_LEFT();
}

int SUBIMAGE_TOP() {
	return IMAGE_PADDING_TOP();
}

// Returns the Hamming Distance between two BRIEF descriptors (bits comparison)
int HAMMING_DISTANCE(const int descs1[getNumberOfKeypoints()],
		const int descs2[getNumberOfKeypoints()]) {
	int i, j;
	int distance = 0;
	for (i = 0; i < DESC_LEN; i++) {
		if (descs1[i] != descs2[i]) {
			distance++;
		}
	}
	return distance;
}

// Returns the width of the subimage shown in the figure above given the original image width:
int SUBIMAGE_WIDTH(const int width) {
	return width - IMAGE_PADDING_TOTAL();
}
// Returns the width of the subimage shown in the figure above given the original image width:
int SUBIMAGE_HEIGHT(const int height) {
	return height - IMAGE_PADDING_TOTAL();
}
// Returns the x-coordinate of the right edge of the subimage
int SUBIMAGE_RIGHT(const int width) {
	return width - IMAGE_PADDING_RIGHT();
}
// Returns the y-coordinate of the bottom edge of the subimage
int SUBIMAGE_BOTTOM(const int height) {
	return height - IMAGE_PADDING_BOTTOM();
}
// Returns pd[row][column]
int GET_MATRIX_DATA(const int* pD, const int row, int column, const int wS) {
	return *(pD + (row * wS) + column);
}

int GET_PIXEL_NW(const int* pD, const CvPoint point, const int wS) {
	return GET_MATRIX_DATA(pD, point.y - HALF_KERNEL_SIZE(),
			point.x - HALF_KERNEL_SIZE(), wS);
}
// Returns the value of north-east corner of the kernel
int GET_PIXEL_NE(const int* pD, const CvPoint point, const int wS) {
	return GET_MATRIX_DATA(pD, point.y - HALF_KERNEL_SIZE(),
			point.x + HALF_KERNEL_SIZE(), wS);
}
// Returns the value of south-west corner of the kernel
int GET_PIXEL_SW(const int* pD, const CvPoint point, const int wS) {
	return GET_MATRIX_DATA(pD, point.y + HALF_KERNEL_SIZE(),
			point.x - HALF_KERNEL_SIZE(), wS);
}
// Returns the value of south-east corner of the kernel
int GET_PIXEL_SE(const int* pD, const CvPoint point, const int wS) {
	return GET_MATRIX_DATA(pD, point.y + HALF_KERNEL_SIZE(),
			point.x + HALF_KERNEL_SIZE(), wS);
}
// Returns a cv::Point2i which is the sum of two cv::Point2i
CvPoint CV_POINT_PLUS(const CvPoint p, const CvPoint delta) {
	return cvPoint(p.x + delta.x, p.y + delta.y);
}

// Construct the integral image at first call
void briefInit() {
	integralImage = cvCreateMat(1, 1, CV_32SC1);
	printf("Before pickTestLocations !\n");

	pickTestLocations();
}

// Destructor
void briefDestroy(void) {
	int i;
	for (i = 0; i < DESC_LEN; i++) {
		testLocations[i].point1 = cvPoint(0, 0);
		testLocations[i].point2 = cvPoint(0, 0);
	}
	cvReleaseMat(&integralImage);
}

void getBriefDescriptors(int descriptors[getNumberOfKeypoints()][DESC_LEN],
		const CvPoint kpts[getNumberOfKeypoints()], IplImage* img) {
	unsigned int i;

	// Make sure that input image contains only one color channel:
	assert(img->nChannels == 1);
	// Check whether all the keypoints are inside the subimage:
	assert(validateKeypoints(kpts, img->width, img->height));

	// Allocate space for the integral image:
	allocateIntegralImage(img);

	// Calculate the integral image:
	cvIntegral(img, integralImage, NULL, NULL);

	// Iterate over keypoints:
	for (i = 0; i < getNumberOfKeypoints(); i++) {
		int inWS = integralImage->step / CV_ELEM_SIZE(integralImage->type);

		int* iD = integralImage->data.i;

		int j;
		for (j = 0; j < DESC_LEN; ++j) {

			const pair tL = testLocations[j];

			const CvPoint p1 = CV_POINT_PLUS(kpts[i], tL.point1);
			const CvPoint p2 = CV_POINT_PLUS(kpts[i], tL.point2);

			const int intensity1 = GET_PIXEL_NW(iD, p1, inWS)
					- GET_PIXEL_NE(iD, p1, inWS) - GET_PIXEL_SW(iD, p1, inWS)
					+ GET_PIXEL_SE(iD, p1, inWS);

			const int intensity2 = GET_PIXEL_NW(iD, p2, inWS)
					- GET_PIXEL_NE(iD, p2, inWS) - GET_PIXEL_SW(iD, p2, inWS)
					+ GET_PIXEL_SE(iD, p2, inWS);

			if (intensity1 < intensity2) {
				descriptors[i][j] = 1;
			} else {
				descriptors[i][j] = 0;
			}
		}
	}
}

void getBriefDescriptors2(int descriptors[getNumberOfKeypoints()][DESC_LEN],
		const CvPoint kpts[getNumberOfKeypoints()], IplImage* img) {
	unsigned int i;

	// Make sure that input image contains only one color channel:
	assert(img->nChannels == 1);
	// Check whether all the keypoints are inside the subimage:
	CvPoint goodArray[getNumberOfKeypoints()];
	assert(validateKeypoints(kpts, img->width, img->height));
	// Allocate space for the integral image:
	allocateIntegralImage(img);

	// Calculate the integral image:
	cvIntegral(img, integralImage, NULL, NULL);

	printf("NumberOfKeypoints : %d\n", getNumberOfKeypoints());

	// Iterate over keypoints:
	for (i = 0; i < getNumberOfKeypoints(); i++) {
		int inWS = integralImage->step / CV_ELEM_SIZE(integralImage->type);

		int* iD = integralImage->data.i;

		int j;
		for (j = 0; j < DESC_LEN; ++j) {

			const pair tL = testLocations[j];

			const CvPoint p1 = CV_POINT_PLUS(kpts[i], tL.point1);
			const CvPoint p2 = CV_POINT_PLUS(kpts[i], tL.point2);

			const int intensity1 = GET_PIXEL_NW(iD, p1, inWS)
					- GET_PIXEL_NE(iD, p1, inWS) - GET_PIXEL_SW(iD, p1, inWS)
					+ GET_PIXEL_SE(iD, p1, inWS);

			const int intensity2 = GET_PIXEL_NW(iD, p2, inWS)
					- GET_PIXEL_NE(iD, p2, inWS) - GET_PIXEL_SW(iD, p2, inWS)
					+ GET_PIXEL_SE(iD, p2, inWS);

			if (intensity1 < intensity2) {
				descriptors[i][j] = 1;
			} else {
				descriptors[i][j] = 0;
			}
		}
	}
}

void pickTestLocations(void) {
	// Pick test locations totally randomly in a way that the locations are inside the patch. Note that
	// number of the tests is equal to the length of the descriptor.
	int i;
	for (i = 0; i < DESC_LEN; ++i) {
		pair *tL = &testLocations[i];

		tL->point1.x = rand() % PATCH_SIZE - HALF_PATCH_SIZE() - 1;
		tL->point1.y = rand() % PATCH_SIZE - HALF_PATCH_SIZE() - 1;
		tL->point2.x = rand() % PATCH_SIZE - HALF_PATCH_SIZE() - 1;
		tL->point2.y = rand() % PATCH_SIZE - HALF_PATCH_SIZE() - 1;
	}
}

bool isKeypointInsideSubImage(const CvPoint keypoint, const int width,
		const int height) {
	if (SUBIMAGE_LEFT() <= keypoint.x && keypoint.x < SUBIMAGE_RIGHT(width)
			&& SUBIMAGE_TOP() <= keypoint.y
			&& keypoint.y < SUBIMAGE_BOTTOM(height)) {
		return true;
	} else {
		return false;
	}

}

bool validateKeypoints(const CvPoint kpts[getNumberOfKeypoints()], int im_w,
		int im_h) {
	unsigned int i;
	for (i = 0; getNumberOfKeypoints(); ++i) {
		if (!isKeypointInsideSubImage(kpts[i], im_w, im_h))
			return false;
		return true;
	}
}

void allocateIntegralImage(const IplImage* img) {
	const int im_w_1 = img->width + 1, im_h_1 = img->height + 1;
	if (im_w_1 != integralImage->cols && im_h_1 != integralImage->rows) {
		cvReleaseMat(&integralImage);
		integralImage = cvCreateMat(im_h_1, im_w_1, CV_32SC1);
	}
}

void setNumberOfKeypoints(int nKpts) {
	numOfKeypoints = nKpts;
}

int getNumberOfKeypoints() {
	return numOfKeypoints;
}
