/***************************************************************************
                          coordinate.cpp  -  description
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

#include "coordinate.h"

Coordinate::Coordinate() {
}

Coordinate::Coordinate(double x, double y) {
	this->x = x;
	this->y = y;
}

Coordinate::~Coordinate(){
}

void
Coordinate::write(std::ostream &stream) const {
	stream << (int)x << " " << (int)y;
}

