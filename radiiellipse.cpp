/***************************************************************************
                          radiiellipse.cpp  -  description
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

#include "radiiellipse.h"

RadiiEllipse::RadiiEllipse() {
	setCode(Object::EllipseCode);
	setSubType(1);
}

RadiiEllipse::RadiiEllipse(Coordinate *center, Coordinate *radii) {
	setCode(Object::EllipseCode);
	setSubType(1);
	this->center = center;
	this->radii = radii;
	this->start = new Coordinate (center->getX(), center->getY());
	this->end = new Coordinate(center->getX()+radii->getX(), center->getY()+radii->getY());
}

RadiiEllipse::~RadiiEllipse() {
}
