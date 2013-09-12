/***************************************************************************
                         coordinate3d.cpp  -  description
                             -------------------
    begin                : Wed Sep 3 2003
    copyright            : (C) 2000-2003 by Anthony Liekens
    email                : anthony@liekens.net
 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/

#include "coordinate3d.h"

Coordinate3D::Coordinate3D() {
}

Coordinate3D::Coordinate3D(double x, double y, double z) {
	this->x = x;
	this->y = y;
	this->z = z;
}

Coordinate3D::~Coordinate3D(){
}

void
Coordinate3D::write(std::ostream &stream) const {
	stream << (int)( 1000 * x / ( z + 500 ) ) << " " << (int)( 1000 * y / ( z + 500 ) );
}

Coordinate* 
Coordinate3D::projection( double xOffset, double yOffset, double scale, double distance ) {
	
	// determine 2 dimensional x, y coordinates
	
	double x2D = ( x * scale ) / ( z + distance ) + xOffset;
	double y2D = ( y * scale ) / ( z + distance ) + yOffset;
	
	return new Coordinate( (int)x2D, (int)y2D );
	
}

void
Coordinate3D::applyMatrix( Matrix< double >* m ) {
	
	double x3D = (*m)[ 0 ][ 0 ] * x +  (*m)[ 0 ][ 1 ] * y + (*m)[ 0 ][ 2 ] * z;
	double y3D = (*m)[ 1 ][ 0 ] * x +  (*m)[ 1 ][ 1 ] * y + (*m)[ 1 ][ 2 ] * z;
	double z3D = (*m)[ 2 ][ 0 ] * x +  (*m)[ 2 ][ 1 ] * y + (*m)[ 2 ][ 2 ] * z;

	x = x3D;
	y = y3D;
	z = z3D;
	
}

void
Coordinate3D::translate( Coordinate3D* c ) {
	
	x += c->getX();
	y += c->getY();
	z += c->getZ();

}
