/* 
* AdjustableParam.cpp
*
* Created: 7/9/2016 9:15:58 AM
* Author: Customer
*/


#include "AdjustableParam.h"

// default constructor
template<typename t>
AdjustableParam<t>::AdjustableParam(t *_refParam, t _min, t _max, t _increment)
{
	refParam = _refParam;
	minValue = _min;
	maxValue = _max;
	incr = _increment;
} //AdjustableParam

// default destructor
template<typename t>
AdjustableParam<t>::~AdjustableParam()
{
} //~AdjustableParam
