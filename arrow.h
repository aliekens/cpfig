/***************************************************************************
                          arrow.h  -  description
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

#ifndef ARROW_H
#define ARROW_H

#include <iostream>

/**This class handles arrows objects. These arrows can be used at the start and end of PolyLine, Arc and Spline instances. See the
	*{@link Attributes::setBackwardArrowBool Attributes::setBackwardArrowBool},
	*{@link Attributes::setBackwardArrowBool Attributes::setBackwardArrowBool},
	*{@link Attributes::getBackwardArrowBool Attributes::getBackwardArrowBool},
	*{@link Attributes::getBackwardArrowBool Attributes::getBackwardArrowBool},
	*{@link Attributes::setBackwardArrow Attributes::setBackwardArrow},
	*{@link Attributes::setBackwardArrow Attributes::setBackwardArrow},
	*{@link Attributes::getBackwardArrow Attributes::getBackwardArrow} and
	*{@link Attributes::getBackwardArrow Attributes::getBackwardArrow} methods for how to use Arrow instances.
  *@author Anthony Liekens
  */

class Arrow {
public:
	/**Enumeration of arrow types.
		*The following arrow types can be used to set the type of an arrow object : {\tt StickArrow, ClosedTriangle, ClosedIntended, ClosedPointed}
		*/
	enum ArrowType { StickArrow = 0,
									 ClosedTriangle = 1,
									 ClosedIntended = 2,
									 ClosedPointed = 3 };
	/**Enumeration of arrow styles.
		*The following arrow styles can be used to set the style of an arrow object : {\tt Hollow, Filled}
		*/
	enum ArrowStyle { Hollow = 0,
										Filled = 1 };
										
protected:
	ArrowType type;
	ArrowStyle style;
	float thickness;
	float width;
	float height;
public:
	/**Constructor.
		*Constructs an Arrow instance
		*/
	Arrow();
	/**Destructor.
		*Destructs an Arrow instance
		*/
	~Arrow();
	
	/**Set the type.
		*@param type {@link Arrow::ArrowType ArrowType}
		*@return void
		*/
	void setType (ArrowType type) { this->type = type; }
	/**Set the style.
		*@param style {@link Arrow::ArrowStyle ArrowStyle}
		*@return void
		*/
	void setStyle (ArrowStyle style) { this->style = style; }
	/**Set the thickness.
		*@param thickness float
		*@return void
		*/
	void setThickness (float thickness) { this->thickness = thickness; }
	/**Set the width.
		*@param width float
		*@return void
		*/
	void setWidth (float width) { this->width = width;}
	/**Set the height.
		*@param heigt float
		*@return void
		*/
	void setHeight (float height) { this->height = height; }
	
	/**Returns the type.
		*@return {@link Arrow::ArrowType ArrowType}
		*/
	ArrowType getType() { return type; }
	/**Returns the style.
		*@return {@link Arrow::ArrowStyle ArrowStyle}
		*/
	ArrowStyle getStyle() { return style; }
	/**Returns the thickness.
		*@return float
		*/
	float getThickness() { return thickness; }
	/**Returns the width.
		*@return float
		*/
	float getWidth() { return width; }
	/**Returns the height.
		*@return float
		*/
	float getHeight() { return height; }
	
	/**Write the coordinate object to a given outstream.
		*@param stream output stream
		*@return void
		*/
	void write(std::ostream &stream) const;
};
	
inline std::ostream &operator<<(std::ostream &stream, const Arrow & a) {
	a.write(stream);
	return stream;
}

#endif
