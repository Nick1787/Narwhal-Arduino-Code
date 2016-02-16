/*
 *        File: LUT.cpp
 *      Author: Nick Dodds <Nick1787@gmail.com>
 * Description: 1D and 2D Lookup Tables
 *				No Extrapolation outside tables bounds
 *				Linear interpolation between points
 * ----------------------------------------------------------------
 *    Revision:
 *		09172015 - NRD - Initial Version
 * ----------------------------------------------------------------
 */
 
#ifndef _LUT_H
#define _LUT_H

#include <Arduino.h>

/**************************
*	LUT1D
**************************/

class LUT1D{
  public:
	//Constructor
	LUT1D(int lenx, float *xvals, float *zvals);
	LUT1D(int lenx, const float *xvals, const float *zvals);
  
    float lookup(float xval);
  private:
    float *_x;
    float *_z;
    int _lenx;
};


/**************************
*	LUT2D
**************************/

class LUT2D{
  public:
	//Constructor
	LUT2D(int lenx, int leny, float *xvals, float *yvals, float *zvals);
	LUT2D(int lenx, int leny, const float *xvals, const float *yvals, const float *zvals);
    float lookup(float xval, float yval);
  private:
    float *_x;
    float *_y;
    float *_z;
    int _lenx;
    int _leny;
};

#endif
