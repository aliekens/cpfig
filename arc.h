/***************************************************************************
                          arc.h  -  description
                             -------------------
    begin                : Tue Sep 5 2000
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

#ifndef ARC_H
#define ARC_H

#include "object.h"
#include "coordinate.h"

/**This class handles arc objects. This class is derived from {@link Object Object}.
  *@author Anthony Liekens
  */

class Arc : public Object {
public:
	/**Enumeration of arc directions.
		*The following directions can be used to set the direction of an arc object : {\tt Clockwise, CounterClockwise}
		*/
	enum Directions { Clockwise, CounterClockwise };
	/**Enumeration of arc types.
		*The following types can be used to set the type of an arc object : {\tt PieWedged, OpenEnded}
		*/
	enum ArcTypes { PieWedged = 0, OpenEnded = 1 };
protected:
	ArcTypes arcType;
	Directions direction;
	double centerX, centerY;
	Coordinate * p1, * p2, * p3;
	
	/**Set the arc direction
		*@param direction {@link Arc::Directions Directions}
		*@return void
		*/
	void setDirection (Directions direction) { this->direction = direction; }
	
	/**Returns the x coordinate of the center of the arc object.
		*@return double
		*/
	double circumCenterX();
	/**Returns the y coordinate of the center of the arc object.
		*@return double
		*/
	double circumCenterY();
	/**Calculates the direction of the arc object.
		*@return {@link Arc::Directions Directions}
		*/
	Directions clockwise();
	/**Returns the determinant of a 3 by 3 matrix. this function is needed for calculating the circumcenter of an arc, and the direction.
		*@param a1 element on row 1, column 1
		*@param a2 element on row 1, column 2
		*@param a3 element on row 1, column 3
		*@param b1 element on row 2, column 1
		*@param b2 element on row 2, column 2
		*@param b3 element on row 2, column 3
		*@param c1 element on row 3, column 1
		*@param c2 element on row 3, column 2
		*@param c3 element on row 3, column 3
		*@return double
		*/
	double determinant(double a1, double a2, double a3, double b1, double b2, double b3, double c1, double c2, double c3);

public:
	/**Constructor.
		*Constructs an arc object.
		*/
	Arc();
	/**Constructor.
		*Constructs an arc object. An arc is defined by giving three points, a start point, an intermediate point and an end point. These three points lay on the arc.
		*@param point1 First Coordinate defining the arc
		*@param point2 Second Coordinate defining the arc
		*@param point3 Third Coordinate defining the arc
		*/
	Arc(Coordinate *point1, Coordinate *point2, Coordinate *point3);
	/**Destructor.
		*Destructs an arc object.
		*/
	~Arc();
	
	/**Set the arc type
		*@param arcType {@link Arc::ArcTypes ArcTypes}
		*@return void
		*/
	void setArcType(ArcTypes arcType) { this->arcType = arcType; }
	
	/**Returns the type of the arc object.
		*@return {@link Arc::ArcTypes ArcTypes}
		*/
	ArcTypes getArcType() { return arcType; }
	/**Returns the direction of the arc object.
		*@return {@link Arc::Directions Directions}
		*/
	Directions getDirection() { return direction; }
	
	/**Write the arc object to a given outstream.
		*@param stream output stream
		*@return void
		*/
	void write(std::ostream &stream) const;
};
	
inline std::ostream &operator<<(std::ostream &stream, const Arc & a) {
	a.write(stream);
	return stream;
}

#endif
