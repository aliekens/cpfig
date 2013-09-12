/***************************************************************************
                          diameterellipse.cpp  -  description
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

#include "diameterellipse.h"

DiameterEllipse::DiameterEllipse() {
	setCode(Object::EllipseCode);
	setSubType(2);
}

DiameterEllipse::DiameterEllipse(Coordinate *start, Coordinate *end) {
	setCode(Object::EllipseCode);
	setSubType(2);
	this->start = start;
	this->end = end;
	this->center = new Coordinate((start->getX()+end->getX())/2, (start->getY()+end->getY())/2);
	this->radii = new Coordinate(fabs(start->getX()-end->getX())/2, fabs(start->getY()-end->getY())/2);
}

DiameterEllipse::~DiameterEllipse() {
}
