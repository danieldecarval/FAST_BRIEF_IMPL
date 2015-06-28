/*
 * brief.c
 *
 * Created on: Jun 17, 2015
 * Author: dani
 */
#include "brief.h"
#define IMAGE_WIDTH 640
#define IMAGE_HEIGHT 480
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
int HAMMING_DISTANCE(const char descs1[getNumberOfKeypoints()],
		const char descs2[getNumberOfKeypoints()]) {
	int i;
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
int GET_PIXEL_NW(const int* pD, const xy point, const int wS) {
	return GET_MATRIX_DATA(pD, point.y - HALF_KERNEL_SIZE(),
			point.x - HALF_KERNEL_SIZE(), wS);
}
// Returns the value of north-east corner of the kernel
int GET_PIXEL_NE(const int* pD, const xy point, const int wS) {
	return GET_MATRIX_DATA(pD, point.y - HALF_KERNEL_SIZE(),
			point.x + HALF_KERNEL_SIZE(), wS);
}
// Returns the value of south-west corner of the kernel
int GET_PIXEL_SW(const int* pD, const xy point, const int wS) {
	return GET_MATRIX_DATA(pD, point.y + HALF_KERNEL_SIZE(),
			point.x - HALF_KERNEL_SIZE(), wS);
}
// Returns the value of south-east corner of the kernel
int GET_PIXEL_SE(const int* pD, const xy point, const int wS) {
	return GET_MATRIX_DATA(pD, point.y + HALF_KERNEL_SIZE(),
			point.x + HALF_KERNEL_SIZE(), wS);
}
// Returns a xy structure which is the sum of two xy structures (like points)
xy POINT_PLUS(const xy p, const xy delta) {
	return (xy ) { p.x + delta.x, p.y + delta.y } ;
		}

// Construct the integral image at first call
		void briefInit() {
			pickTestLocations();
		}
// Destructor
		void briefDestroy(void) {
			int i;
			xy coordinatesZero = (xy ) { 0, 0 };
			for (i = 0; i < DESC_LEN; i++) {
				testLocations[i].point1 = coordinatesZero;
				testLocations[i].point2 = coordinatesZero;
			}
		}
		void getBriefDescriptors(
				char descriptors[getNumberOfKeypoints()][DESC_LEN],
				const xy kpts[getNumberOfKeypoints()], IplImage* img) {
			unsigned int i, j;

// Make sure that input image contains only one color channel:
			assert(img->nChannels == 1);
// Check whether all the keypoints are inside the subimage:
			assert(validateKeypoints(kpts, img->width, img->height));

			int width = img->width;
			int height = img->height;

			int matrix[height][width];
			int x, y;
			for (x = 0; x < height; x++) {
				for (y = 0; y < width; y++) {
					matrix[x][y] = GET_IMAGE_ELEMENT(img, uchar, x, y);
				}
			}

			int sat[height + 1][width + 1];
			computeIntegral(width, height, matrix, sat);

			CvMat *integralImageOpenCV = cvCreateMat(height + 1, width + 1, CV_32SC1);
			cvIntegral(img, integralImageOpenCV, NULL, NULL);

			cvShowImage("Integral d'OpenCV", integralImageOpenCV);
			cvWaitKey(0);

			CvMat *integralImage = cvCreateMat(height + 1, width + 1, CV_32SC1);

			integralImage->data.i = sat;

			cvShowImage("Mon Image Integral", integralImage);
			cvWaitKey(0);
			int type = 1111638020;
			int step = 2564;
// Iterate over keypoints:
			for (i = 0; i < getNumberOfKeypoints(); i++) {
				int inWS = step / sizeof(type);
				int* iD = sat;
				for (j = 0; j < DESC_LEN; ++j) {
					const pair tL = testLocations[j];
					const xy p1 = POINT_PLUS(kpts[i], tL.point1);
					const xy p2 = POINT_PLUS(kpts[i], tL.point2);
					const int intensity1 = GET_PIXEL_NW(iD, p1, inWS)
							- GET_PIXEL_NE(iD, p1, inWS)
							- GET_PIXEL_SW(iD, p1, inWS)
							+ GET_PIXEL_SE(iD, p1, inWS);
					const int intensity2 = GET_PIXEL_NW(iD, p2, inWS)
							- GET_PIXEL_NE(iD, p2, inWS)
							- GET_PIXEL_SW(iD, p2, inWS)
							+ GET_PIXEL_SE(iD, p2, inWS);
					if (intensity1 < intensity2) {
						descriptors[i][j] = 1;
					} else {
						descriptors[i][j] = 0;
					}
				}
			}
		}

		void computeIntegral(int width, int height, int matrix[height][width],
				int sat[height + 1][width + 1]) {
			int a = 0;
			int b1 = 0;
			int c = 0;
			int m = 0;
			int x, y;

			FILE* integralFinal;
			integralFinal = fopen("integralFinal.txt", "w+");
			for (x = 0; x < height + 1; x++) {
				for (y = 0; y < width + 1; y++) {
					a = (x - 1 >= 0) ? sat[x - 1][y] : 0;
					b1 = (y - 1 >= 0) ? sat[x][y - 1] : 0;
					c = ((x - 1 >= 0) && (y - 1 >= 0)) ? sat[x - 1][y - 1] : 0;
					m = ((x - 1 >= 0) && (y - 1 >= 0)) ?
							matrix[x - 1][y - 1] : 0;

					sat[x][y] = m + a + b1 - c;
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
		bool isKeypointInsideSubImage(const xy keypoint, const int width,
				const int height) {
			if (SUBIMAGE_LEFT() <= keypoint.x
					&& keypoint.x < SUBIMAGE_RIGHT(width)
					&& SUBIMAGE_TOP() <= keypoint.y
					&& keypoint.y < SUBIMAGE_BOTTOM(height)) {
				return true;
			} else {
				return false;
			}
		}
		bool validateKeypoints(const xy kpts[getNumberOfKeypoints()], int im_w,
				int im_h) {
			unsigned int i;
			for (i = 0; getNumberOfKeypoints(); ++i) {
				if (!isKeypointInsideSubImage(kpts[i], im_w, im_h))
					return false;
				return true;
			}
			return true;
		}

		void setNumberOfKeypoints(int nKpts) {
			numOfKeypoints = nKpts;
		}
		int getNumberOfKeypoints() {
			return numOfKeypoints;
		}

