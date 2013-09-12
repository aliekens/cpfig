/***************************************************************************
                          box.cpp  -  description
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

#include "box.h"

Box::Box(){
	setCode(Object::PolyLineCode);
	setSubType(BoxType);
}

Box::Box(Coordinate *a, Coordinate *b) {
	setCode(Object::PolyLineCode);
	setSubType(BoxType);
	push_back(a);
	Coordinate *c = new Coordinate(a->getX(), b->getY());
	push_back(c);
	push_back(b);
	Coordinate *d = new Coordinate(b->getX(), a->getY());
	push_back(d);
	push_back(a);
}

Box::~Box(){
}
