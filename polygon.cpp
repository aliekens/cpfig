/***************************************************************************
                          polygon.cpp  -  description
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

#include "polygon.h"

Polygon::Polygon(){
	setCode(Object::PolyLineCode);
	setSubType(PolygonType);
}

Polygon::Polygon(Coordinate *a, Coordinate *b) {
	setCode(Object::PolyLineCode);
	setSubType(PolygonType);
	push_back(a);
	push_back(b);
}

Polygon::~Polygon() {
}
