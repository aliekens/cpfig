/***************************************************************************
                          splinecoordinate.cpp  -  description
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

#include "splinecoordinate.h"

SplineCoordinate::SplineCoordinate(){
}

SplineCoordinate::SplineCoordinate(int x, int y, float shapeFactor){
	this->x = x;
	this->y = y;
	this->shapeFactor = shapeFactor;
}

SplineCoordinate::SplineCoordinate(Coordinate *c, float shapeFactor){
	this->x = c->getX();
	this->y = c->getY();
	this->shapeFactor = shapeFactor;
}

SplineCoordinate::~SplineCoordinate(){
}
