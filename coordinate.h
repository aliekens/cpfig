/***************************************************************************
                          coordinate.h  -  description
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

#ifndef COORDINATE_H
#define COORDINATE_H

#include <math.h>

#include <iostream>

/**This class handles coordinates. Remember that computers use coordinate systems that are upside-down. This means that the origin of the coordinate system lays in the top-left corner, so the Y axis is upside-down...
	*You will notice that a lot of objects use pointers to Coordinates in constructors, etc. This is because the library needs to be generic, so you can use inherited Coordinates as Coordinates too (for example SplineCoordinate instances).
  *@author Anthony Liekens
  */

class Coordinate {
protected:
	double x, y;
	
public:
	/**Constructor. Constructs a coordinate.
		*/
	Coordinate();
	/**Constructor. Constructs a coordinate.
		*@param x Integer X-axis value of the coordinate (0 = leftmost point)
		*@param y Integer Y-axis value of the coordinate (0 = top)
		*/
	Coordinate(double x, double y);
	/**Destructor. Destructs a coordinate.
		*/
	~Coordinate();
	
	/**Set the X-axis value.
		*@param x double value
		*@return void
		*/
	void setX(double x) { this->x = x; }
	/**Set the Y-axis value.
		*@param y double value
		*@return void
		*/
	void setY(double y) { this->y = y; }
	/**Returns the X-axis value of the coordinate.
		*@return double
		*/
	double getX() { return x; }
	/**Returns the Y-axis value of the coordinate.
		*@return double
		*/
	double getY() { return y; }
	
	/**Returns the distance between this coordinate and another point.
		*@param c Coordinate of that other point
		*@return int
		*/
	double distance(Coordinate *c) {
		double dx = getX()-c->getX();
		double dy = getY()-c->getY();
		return sqrt(dx*dx+dy*dy);
	}
	
	/**Write the coordinate object to a given outstream.
		*@param stream output stream
		*@return void
		*/
	void write(std::ostream &stream) const;
};
	
inline std::ostream &operator<<(std::ostream &stream, const Coordinate & c) {
	c.write(stream);
	return stream;
}

#endif
