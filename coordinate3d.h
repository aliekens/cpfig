/***************************************************************************
                         coordinate3d.h  -  description
                             -------------------
    begin                : Wed Sep 3 2003
    copyright            : (C) 2000-2003 by Anthony Liekens
    email                : anthony@liekens.net
 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/

#ifndef COORDINATE3D_H
#define COORDINATE3D_H

#include <math.h>

#include <iostream>

#include "coordinate.h"
#include "matrix.h"

/**This class handles coordinates. Remember that computers use coordinate systems that are upside-down. This means that the origin of the coordinate system lays in the top-left corner, so the Y axis is upside-down...
	*You will notice that a lot of objects use pointers to Coordinates in constructors, etc. This is because the library needs to be generic, so you can use inherited Coordinates as Coordinates too (for example SplineCoordinate instances).
  *@author Anthony Liekens
  */

class Coordinate3D {
protected:
	double x, y, z;
	
public:
	/**Constructor. Constructs a coordinate.
		*/
	Coordinate3D();
	/**Constructor. Constructs a coordinate.
		*@param x Integer X-axis value of the coordinate (0 = leftmost point)
		*@param y Integer Y-axis value of the coordinate (0 = top)
		*/
	Coordinate3D(double x, double y, double z);
	/**Destructor. Destructs a coordinate.
		*/
	~Coordinate3D();
	
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
	/**Set the Z-axis value.
		*@param z double value
		*@return void
		*/
	void setZ(double z) { this->z = z; }
	
	/**Returns the X-axis value of the coordinate.
		*@return double
		*/
	double getX() { return x; }
	/**Returns the Y-axis value of the coordinate.
		*@return double
		*/
	double getY() { return y; }
	/**Returns the Y-axis value of the coordinate.
		*@return double
		*/
	double getZ() { return z; }
	
	/**Returns the distance between this coordinate and another point.
		*@param c Coordinate3D of that other point
		*@return double
		*/
	double distance(Coordinate3D *c) {
		double dx = getX()-c->getX();
		double dy = getY()-c->getY();
		double dz = getZ()-c->getZ();
		return (double)sqrt(dx*dx+dy*dy+dz*dz);
	}
	
	Coordinate* projection( double xOffset, double yOffset, double scale, double distance );
	void applyMatrix( Matrix< double >* );
	void translate( Coordinate3D* );
	
	/**Write the coordinate object to a given outstream.
		*@param stream output stream
		*@return void
		*/
	void write(std::ostream &stream) const;
};
	
inline std::ostream &operator<<(std::ostream &stream, const Coordinate3D & c) {
	c.write(stream);
	return stream;
}

#endif