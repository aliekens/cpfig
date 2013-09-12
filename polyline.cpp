/***************************************************************************
                          polyline.cpp  -  description
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

#include "polyline.h"

PolyLine::PolyLine() {
	setCode(Object::PolyLineCode);
	setSubType(PolyLineType);
}

PolyLine::PolyLine(Coordinate *a, Coordinate *b) {
	setCode(Object::PolyLineCode);
	setSubType(PolyLineType);
	push_back(a);
	push_back(b);
}

PolyLine::~PolyLine() {
}

void
PolyLine::write(std::ostream &stream) const {
	stream << "# polyline\n";
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
	stream << joinStyle << " ";
	stream << capStyle << " ";
	stream << radius << " ";
	if (subType==1) {
		stream << forwardArrowBool << " ";
		stream << backwardArrowBool << " ";
	} else {
		stream << 0 << " " << 0 << " ";
	}
	if (subType==3)
		stream << size()+1 << "\n";
	else
		stream << size() << "\n";
	if (subType==1) {
		if (forwardArrowBool)
			stream << "\t" << forwardArrow;
		if (backwardArrowBool)
			stream << "\t" << backwardArrow;
	}
	stream << "\t";
	for (const_iterator i = begin(); i != end(); i++)
		stream << (*(*i)) << " ";
	if (subType==3)
		stream << (*(*begin())) << " ";
	stream << "\n";
}
