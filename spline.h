/***************************************************************************
                          spline.h  -  description
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

#ifndef SPLINE_H
#define SPLINE_H

#include <vector>

#include "object.h"
#include "splinecoordinate.h"

/**This class handles spline objects. This class is derived from {@link Object Object}.
  *@author Anthony Liekens
  */

class Spline : public Object, public std::vector<SplineCoordinate*> {
public:
	enum SubTypes {Opened, Closed};
private:
	SubTypes subType;
public:
	Spline();
	Spline(SplineCoordinate *, SplineCoordinate *);
	~Spline();
	
	void setSubType (SubTypes subType) { this->subType = subType; }
	SubTypes getSubType () { return subType; }
	
	void write(std::ostream &stream) const;
};
	
inline std::ostream &operator<<(std::ostream &stream, const Spline & s) {
	s.write(stream);
	return stream;
}

#endif
