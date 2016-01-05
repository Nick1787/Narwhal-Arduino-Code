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
 
#include "LUT.h"

/**************************
*	LUT1D
**************************/

//---Constructor-----

LUT1D::LUT1D(int lenx, float *xvals, float *zvals){
	//Copy the X data
	_lenx=lenx;
	float xvals_temp[lenx];
	_x = xvals_temp;
	memcpy(&_x, &xvals, sizeof xvals);

	//Copy the z data
	float zvals_temp[lenx];
	_z=zvals_temp;
	memcpy(&_z, &zvals, sizeof zvals);
}

//---lookup-----

float LUT1D::lookup(float xval){
  if( xval <= _x[0]){
     return _z[0]; 
  }else{
    if( xval >= _x[_lenx-1]){
      return _z[_lenx-1];
    }else{
      // In the Middel of Table, interpolate to find value.
      int ix = 0;
      for ( ix = 0; ix < _lenx - 1 ; ix++ )
      {
          //Find the location we are in the table.
          if( (xval >= _x[ix]) && (xval < _x[ix+1])){
              break;
          }
      }
      
      //Interpolate z value
      return ((xval - _x[ix])*((_z[ix+1] - _z[ix])/(_x[ix+1]-_x[ix])) + _z[ix]);
    }
  }
}


/**************************
*	LUT2D
**************************/

//---Constructor-----

LUT2D::LUT2D(int lenx, int leny, float *xvals, float *yvals, float *zvals){
	//Copy the X data
	_lenx=lenx;
	float xvals_temp[lenx];
	_x = xvals_temp;
	memcpy(&_x, &xvals, sizeof xvals);
	
	//Copy the Y data
	_leny=leny;
	float yvals_temp[leny];
	_y = yvals_temp;
	memcpy(&_y, &yvals, sizeof yvals);

	//Copy the z data
	float zvals_temp[lenx][leny];
	_z=&zvals_temp[0][0];
	memcpy(&_z, &zvals, sizeof zvals);
}

//---lookup-----

