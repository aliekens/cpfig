/***************************************************************************
                          polyline.h  -  description
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

#ifndef POLYLINE_H
#define POLYLINE_H


/**This class handles polyline objects. This class is derived from {@link Object Object}. It acts as a vector (C++ standard library) container for instances of {@link Coordinate Coordinate}
  *@author Anthony Liekens
  */

#include <vector>
#include <iostream>

#include "object.h"
#include "coordinate.h"

class PolyLine : public Object, public std::vector<Coordinate *> {
public:
	/**Enumeration of polyline types.
		The following types can be used to set the type of a polyline object : {\tt PolyLineType, BoxType, PolygonType, PictureType}.
		Inherited polyline classes will set their appropriate type.
		*/
	enum SubTypes {PolyLineType =  1, BoxType = 2, PolygonType = 3, ArcBoxType = 4, PictureType = 5};
private:
	SubTypes subType;
protected:
	/**Set the sub type
		*@param subType {@link PolyLine::SubTypes SubTypes}
		*@return void
		*/
	void setSubType (SubTypes subType) { this->subType = subType; }
public:
	/**Constructor. Constructs a polyline object
		*/
	PolyLine();
	/**Constructor. Constructs a polyline object with 2 points
		*@param point1 - Instance of {@link Coordinate Coordinate}. Coordinates of the first point
		*@param point2 - Instance of {@link Coordinate Coordinate}. Coordinates of the second point
		*/
	PolyLine(Coordinate *point1, Coordinate *point2);
	/**Destructor. Destructs a polyline object
		*/
	~PolyLine();
	
	/**Returns the polyline sub type
		*@return Instance of {@link PolyLine::SubTypes SubTypes}
		*/
	int getSubType () { return subType; }
	
	/**Write the polyline object to a given outstream.
		*@param stream output stream
		*@return void
		*/
	void write(std::ostream &stream) const;
};
	
inline std::ostream &operator<<(std::ostream &stream, const PolyLine & p) {
	p.write(stream);
	return stream;
}

#endif
