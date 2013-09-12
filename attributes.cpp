/***************************************************************************
                          attributes.cpp  -  description
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

#include "attributes.h"

Attributes::Attributes() {
	setLineStyle(Solid);
	setThickness(1);
	setPenColor(Black);
	setFillColor(White);
	setDepth(50);	
	setPenStyle(0);
	setAreaFill(-1);
	setStyleVal(5.000);
	setJoinStyle(0);
	setCapStyle(1);
	setRadius(-1);
	setForwardArrowBool(0);
	setBackwardArrowBool(0);	
	setFont(TimesRoman);
	setFontFlags(LatexPostScript);
	setFontSize(12);
	setAngle(0);
	setHeight(135);
	setLength(360);
}

Attributes::~Attributes() {
}

void
Attributes::setAttributes(Attributes a) {
	setLineStyle (a.getLineStyle());
	setThickness (a.getThickness());
	setPenColor (a.getPenColor());
	setFillColor (a.getFillColor());
	setDepth (a.getDepth());
	setPenStyle (a.getPenStyle());
	setAreaFill (a.getAreaFill());
	setStyleVal (a.getStyleVal());
	setJoinStyle (a.getJoinStyle());
	setCapStyle (a.getCapStyle());
	setRadius (a.getRadius());
	setForwardArrowBool (a.getForwardArrowBool());
	setBackwardArrowBool (a.getBackwardArrowBool());
	setForwardArrow (a.getForwardArrow());
	setBackwardArrow (a.getBackwardArrow());
	setFont( a.getFont() );
	setFontSize( a.getFontSize() );
}
