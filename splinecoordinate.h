/***************************************************************************
                          splinecoordinate.h  -  description
                             -------------------
    begin                : Thu Sep 7 2000
    copyright            : (C) 2000 by Anthony Liekens
    email                : mooby@alife.org
 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/

#ifndef SPLINECOORDINATE_H
#define SPLINECOORDINATE_H

#include "coordinate.h"

/**This class handles coordinates to be used in splines. This class is derived from {@link Coordinate Coordinate}.
  *@author Anthony Liekens
  */

class SplineCoordinate : public Coordinate  {
private:
	float shapeFactor;
public:
	/**Constructor.
		*Constructs a spline coordinate.
		*/
	SplineCoordinate();
	/**Constructor.
		*Constructs a spline coordinate.
		*@param x X-axis value of the coordinate
		*@param y Y-axis value of the coordinate
		*@param shapeFactor The value of this factor must be between -1 (which means that the spline is interpolated at this point)
		*and 1 (which means that the spline is approximated at this point). The spline is always smooth in the neighbourhood of a control
		*point, except when the value of the factor is 0 for which there is a first-order discontinuity (i.e. angular point).
		*/
	SplineCoordinate(int x, int y, float shapeFactor);
	/**Constructor.
		*Constructs a spline coordinate.
		*@param c Coordinate of the spline coordinate
		*@param shapeFactor The value of this factor must be between -1 (which means that the spline is interpolated at this point)
		*and 1 (which means that the spline is approximated at this point). The spline is always smooth in the neighbourhood of a control
		*point, except when the value of the factor is 0 for which there is a first-order discontinuity (i.e. angular point).
		*/
	SplineCoordinate(Coordinate *c, float shapefactor);
	/**Destructor.
		*Destructs a spline coordinate.
		*/
	~SplineCoordinate();
	
	/**Set the shape factor
		*@param shapeFactor The value of this factor must be between -1 (which means that the spline is interpolated at this point)
		*and 1 (which means that the spline is approximated at this point). The spline is always smooth in the neighbourhood of a control
		*point, except when the value of the factor is 0 for which there is a first-order discontinuity (i.e. angular point).
		*@return void
		*/
	void setShapeFactor(float shapeFactor) { this->shapeFactor = shapeFactor; }
	/**Returns the shape factor.
		*@return float
		*/
	float getShapeFactor() { return shapeFactor; }
};

#endif
