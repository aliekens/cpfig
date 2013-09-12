/***************************************************************************
                          spline.cpp  -  description
                             -------------------
    begin                : Thu Sep 7 2000
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

#include "spline.h"

Spline::Spline(){
	setCode(Object::SplineCode);
	setSubType(Opened);
}

Spline::Spline(SplineCoordinate *a, SplineCoordinate *b){
	setCode(Object::SplineCode);
	setSubType(Opened);
	push_back(a);
	push_back(b);
}

Spline::~Spline(){
}

void
Spline::write(std::ostream &stream) const {
	stream << "# spline\n";
	stream << code << " ";
	switch (subType) {
		case Opened:
			stream << 4 << " ";
		break;
		case Closed:
			stream << 5 << " ";
		break;
	}
	stream << lineStyle << " ";
	stream << thickness << " ";
	stream << penColor << " ";
	stream << fillColor << " ";
	stream << depth << " ";
	stream << penStyle << " ";
	stream << areaFill << " ";
	stream << styleVal << " ";
	stream << capStyle << " ";
	if (subType==4) {
		stream << forwardArrowBool << " ";
		stream << backwardArrowBool << " ";
	} else {
		stream << 0 << " " << 0 << " ";
	}
	if (subType==5)
		stream << size()+1 << "\n";
	else
		stream << size() << "\n";
	if (subType==4) {
		if (forwardArrowBool)
			stream << "\t" << forwardArrow;
		if (backwardArrowBool)
			stream << "\t" << backwardArrow;
	}
	stream << "\t";
	for (const_iterator i = begin(); i != end(); i++)
		stream << (*(*i)) << " ";
	if (subType==5)
		stream << (*(*begin())) << " ";
	stream << "\n";
	stream << "\t";
	for (const_iterator i = begin(); i != end(); i++)
		stream << (*i)->getShapeFactor() << " ";
	if (subType==5)
		stream << (*begin())->getShapeFactor() << " ";
	stream << "\n";
}
