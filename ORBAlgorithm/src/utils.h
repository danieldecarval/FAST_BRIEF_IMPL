/*
 * utils.h
 *
 *  Created on: Jun 22, 2015
 *      Author: dani
 */

#ifndef UTILS_H_
#define UTILS_H_
#include <cv.h>

struct {
	float *data;               // actual data
	const IplImage* src;       // source image

} cur_int_img_;           // current integral image, recomputed only when needed

typedef struct {
	int x, y;
} xy;
typedef unsigned char byte;

#define GET_IMAGE_ELEMENT( image, elemtype, row, col ) (((elemtype*)((image)->imageData + (image)->widthStep*(row)))[(col)])

#endif /* UTILS_H_ */
