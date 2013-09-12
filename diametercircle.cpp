/***************************************************************************
                          diametercircle.cpp  -  description
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

#include "diametercircle.h"

DiameterCircle::DiameterCircle() {
	setCode(Object::EllipseCode);
	setSubType(4);
}

DiameterCircle::DiameterCircle(Coordinate *start, Coordinate *end) {
	setCode(Object::EllipseCode);
	setSubType(4);
	this->start = start;
	this->end = end;
	center = new Coordinate((start->getX()+end->getX())/2,(start->getY()+end->getY())/2);
	radii = new Coordinate(start->distance(end)/2, start->distance(end)/2);
}

DiameterCircle::~DiameterCircle() {
}
