/***************************************************************************
                          object.h  -  description
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

#ifndef OBJECT_H
#define OBJECT_H

#include <iostream>

#include "attributes.h"

/**This generic class handles objects. This class is derived from {@link Attributes Attributes}.
  *@author Anthony Liekens
  */

class Object : public Attributes{
public:
	/**Enumeration of object codes.
		The following object codes can be used to set the code of an object : {\tt PseudoColor, Arc, Compound, Ellips, PolyLine, Spline, Text}
		*/
	enum ObjectCodes {PseudoColorCode = 0, ArcCode = 5, CompoundCode = 6, EllipseCode = 1, PolyLineCode = 2, SplineCode = 3, TextCode = 4};

protected:
	ObjectCodes code;
	
	/**Sets the code of an object. This method can only be called by instances of {@link Object Object}
		*@param code integer value
		*@return void
		*/
	void setCode(ObjectCodes code) { this->code = code; }

public:
	/**Constructor. This constructor does nothing special, since this is a generic and abstract class
		*/
	Object();
	/**Destructor.
		*/
	virtual ~Object();
	
	/**Returns the code of an object
		*/
	ObjectCodes getCode() { return code; }
	
	/**Write the object to a given outstream. All inherited classes of object should provide this method, since it's called
		*by {@link Figure Figure} (the object container) to output objects to a given stream.
		*@param stream output stream
		*@return void
		*/
	virtual void write(std::ostream &stream) const { stream << "# error - a class did not implement the write method\n"; }
};
	
inline std::ostream &operator<<(std::ostream &stream, const Object & o) {
	o.write(stream);
	return stream;
}

#endif
