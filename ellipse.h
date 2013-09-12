/***************************************************************************
                          ellipse.h  -  description
                             -------------------
    begin                : Mon Sep 4 2000
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

#ifndef ELLIPSE_H
#define ELLIPSE_H

#include "object.h"

#include "object.h"
#include "coordinate.h"

/**This class handles ellipses and circles. This class is derived from {@link Object Object}.
  *@author Anthony Liekens
  */

class Ellipse : public Object  {
protected:
	int subType;						// 1: ellipse defined by radii,
													// 2: ellipse defined by diameters,
													// 3: circle defined by radius,
													// 4: circle defined by diameter
	int direction;					// allways 1
	float angle;						// radians, angle of X-axis
	Coordinate *center;
	Coordinate *radii;
	Coordinate *start, *end;
	
	void setSubType(int subType) { this->subType = subType; }
	
public:
	Ellipse();
	~Ellipse();
	
	int getSubType() { return subType; }
	void setAngle(float angle) { this->angle = angle; }
	float getAngle() { return angle; }
	void setCenter(Coordinate *center) { this->center = center; }
	Coordinate * getCenter() { return center; }
	void setRadii(Coordinate *radius) { this->radii = radii; }
	Coordinate * getRadii() { return radii; }
	void setStart(Coordinate *start) { this->start = start; }
	Coordinate * getStart() { return start; }
	void setEnd(Coordinate *end) { this->end = end; }
	Coordinate * getEnd() { return end; }
	
	void write(std::ostream &stream) const;
};
	
inline std::ostream &operator<<(std::ostream &stream, const Ellipse & o) {
	o.write(stream);
	return stream;
}

#endif
