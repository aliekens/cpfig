/***************************************************************************
                          arrow.cpp  -  description
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

#include "arrow.h"

Arrow::Arrow() {
	setType(StickArrow);
	setStyle(Hollow);
	setThickness(1.00);
	setWidth(60.00);	
	setHeight(120.00);
}

Arrow::~Arrow() {
}

void
Arrow::write(std::ostream &stream) const {
	stream << type << " ";
	stream << style << " ";
	stream << thickness << " ";
	stream << width << " ";
	stream << height << "\n";
}
