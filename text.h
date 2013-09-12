/***************************************************************************
                          text.h  -  description
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

#ifndef TEXT_H
#define TEXT_H

#include <string>

#include "object.h"
#include "coordinate.h"

/**This class handles text objects. This class is derived from {@link Object Object}.
  *@author Anthony Liekens
  */

class Text : public Object  {
public:
	/**Enumeration of text justifications.
		The following justifications can be used to set the justification of a text object : {\tt LeftJustified, CenterJustified, RightJustified}
		*/
	enum TextJustifications { LeftJustified = 0,
									 CenterJustified = 1,
									 RightJustified = 2 };
protected:
	TextJustifications justification;
	Coordinate *place;
	std::string contents;
	
public:
	/**Constructor. Constructs a text object
		*/
	Text();
	/**Constructor. Constructs a text object
		*@param place - Instance of {@link Coordinate Coordinate}. Coordinates where the text object will be placed.
		*@param contents - string
		*/
	Text(Coordinate *place, std::string contents);
	~Text();
	
	/**Set the text justification
		*@param justification {@link Text::TextJustifications TextJustifications}
		*@return void
		*/
	void setJustification(TextJustifications justification) { this->justification = justification; }
	/**Returns the text justification
		*@return Instance of {@link Text::TextJustifications TextJustifications}
		*/
	TextJustifications getJustification() { return justification; }
	
	/**Write the text object to a given outstream.
		*@param stream output stream
		*@return void
		*/
	void write(std::ostream &stream) const;
};
	
inline std::ostream &operator<<(std::ostream &stream, const Text & o) {
	o.write(stream);
	return stream;
}

#endif
