/***************************************************************************
                          text.cpp  -  description
                             -------------------
    begin                : Tue Sep 5 2000
    copyright            : (C) 2000 by 
    email                : 
 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/

#include "text.h"

Text::Text() {
	setCode(Object::TextCode);
	setJustification(LeftJustified);
}

Text::Text(Coordinate *place, std::string text) {
	setCode(Object::TextCode);
	setJustification(LeftJustified);
	this->place = place;
	this->contents = text;
}

Text::~Text() {
}

void
Text::write(std::ostream &stream) const {
	stream << "# text\n";
	stream << code << " ";
	stream << justification << " ";
	stream << penColor << " ";
	stream << depth << " ";
	stream << penStyle << " ";
	stream << font << " ";
	stream << fontSize << " ";
	stream << angle << " ";
	stream << fontFlags << " ";
	stream << height << " ";
	stream << length << " ";
	stream << *place << " ";
	stream << contents << "\\001\n";
}
