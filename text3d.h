/***************************************************************************
                         text3d.h  -  description
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

#ifndef TEXT3D_H
#define TEXT3D_H

#include <string>

#include "text.h"

#include "object3d.h"
#include "coordinate3d.h"

/**This class handles text objects. This class is derived from {@link Object Object}.
  *@author Anthony Liekens
  */

class Text3D : public Object3D {

protected:
	Text::TextJustifications justification;
	Coordinate3D *place;
	std::string contents;
	
public:
	/**Constructor. Constructs a text object
		*/
	Text3D();
	/**Constructor. Constructs a text object
		*@param place - Instance of {@link Coordinate Coordinate}. Coordinates where the text object will be placed.
		*@param contents - string
		*/
	Text3D(Coordinate3D *place, std::string contents);
	~Text3D();
	
	/**Set the text justification
		*@param justification {@link Text3D::TextJustifications TextJustifications}
		*@return void
		*/
	void setJustification(Text::TextJustifications justification) { this->justification = justification; }
	/**Returns the text justification
		*@return Instance of {@link Text3D::TextJustifications TextJustifications}
		*/
	Text::TextJustifications getJustification() { return justification; }
	
	std::pair< double, double> getDepthRange();
	void render( Figure*, double xOffset, double yOffset, double scale, double distance, double minDepth, double maxDepth, int minFigDepth = 0, int maxFigDepth = 999 );
	void applyMatrix( Matrix< double >* );
	void translate( Coordinate3D* );

	/**Write the text object to a given outstream.
		*@param stream output stream
		*@return void
		*/
	void write(std::ostream &stream) const;
};
	
inline std::ostream &operator<<(std::ostream &stream, const Text3D & o) {
	o.write(stream);
	return stream;
}

#endif
