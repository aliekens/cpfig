/***************************************************************************
                          ellipse.cpp  -  description
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

#include "ellipse.h"

Ellipse::Ellipse(){
}

Ellipse::~Ellipse(){
	delete center;
	delete start;
	delete end;
	delete radii;
}

void
Ellipse::write(std::ostream &stream) const {
	stream << "# ellipse\n";
	stream << code << " ";
	stream << subType << " ";
	stream << lineStyle << " ";
	stream << thickness << " ";
	stream << penColor << " ";
	stream << fillColor << " ";
	stream << depth << " ";
	stream << penStyle << " ";
	stream << areaFill << " ";
	stream << styleVal << " ";
	stream << direction << " ";
	stream << angle << " ";
	stream << *center << " ";
	stream << *radii << " ";
	stream << *start << " ";
	stream << *end << " ";
	stream << "\n";
}
