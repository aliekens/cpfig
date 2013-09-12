/***************************************************************************
                          radiuscircle.cpp  -  description
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

#include "radiuscircle.h"

RadiusCircle::RadiusCircle() {
	setCode(Object::EllipseCode);
	setSubType(3);
}

RadiusCircle::RadiusCircle(Coordinate *center, int radius) {
	setCode(Object::EllipseCode);
	setSubType(3);
	this->center = center;
	this->radii = new Coordinate(radius, radius);
	this->start = new Coordinate(center->getX(), center->getY());
	this->end = new Coordinate(center->getX()+radius, center->getY());
}

RadiusCircle::~RadiusCircle() {
}
