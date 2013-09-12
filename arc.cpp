/***************************************************************************
                          arc.cpp  -  description
                             -------------------
    begin                : Tue Sep 5 2000
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

#include "arc.h"

Arc::Arc(){
	setCode(Object::ArcCode);
	setArcType(OpenEnded);
}

Arc::Arc(Coordinate *p1, Coordinate *p2, Coordinate *p3){
	setCode(Object::ArcCode);
	setArcType(OpenEnded);
	this->p1 = p1;
	this->p2 = p2;
	this->p3 = p3;
	centerX = circumCenterX();
	centerY = circumCenterY();
	if (clockwise())
		setDirection(Clockwise);
	else
		setDirection(CounterClockwise);
}

Arc::~Arc(){
}

void
Arc::write(std::ostream &stream) const {
	stream << "# arc\n";
	stream << code << " ";
	stream << arcType << " ";
	stream << lineStyle << " ";
	stream << thickness << " ";
	stream << penColor << " ";
	stream << fillColor << " ";
	stream << depth << " ";
	stream << penStyle << " ";
	stream << areaFill << " ";
	stream << styleVal << " ";
	stream << capStyle << " ";
	stream << direction << " ";
	stream << forwardArrowBool << " ";
	stream << backwardArrowBool << " ";
	stream << centerX << " " << centerY << " ";
	stream << *p1 << " ";
	stream << *p2 << " ";
	stream << *p3 << "\n";
	if (forwardArrowBool)
		stream << "\t" << forwardArrow;
	if (backwardArrowBool)
		stream << "\t" << backwardArrow;
}

Arc::Directions
Arc::clockwise() {
	double x1 = p1->getX();
	double y1 = p1->getY();
	double x2 = p2->getX();
	double y2 = p2->getY();
	double x3 = p3->getX();
	double y3 = p3->getY();
	double det = determinant( x1, y1, 1, x2, y2, 1, x3, y3, 1 );
	if( det > 0 )
		return Clockwise;
	else
		return CounterClockwise;
}

double
Arc::circumCenterX() {
	// this function calculates the circumcenter of three points
	// see: http://www.mathworld.com
	double x1 = p1->getX();
	double y1 = p1->getY();
	double x2 = p2->getX();
	double y2 = p2->getY();
	double x3 = p3->getX();
	double y3 = p3->getY();
	double s1 = x1*x1+y1*y1;
	double s2 = x2*x2+y2*y2;
	double s3 = x3*x3+y3*y3;
	double a = determinant(x1, y1, 1, x2, y2, 1, x3, y3, 1);
	double d = -determinant(s1, y1, 1, s2, y2, 1, s3, y3, 1);
	return -d/(2*a);
}

double
Arc::circumCenterY() {
	// this function calculates the circumcenter of three points
	// see: http://www.mathworld.com
	double x1 = p1->getX();
	double y1 = p1->getY();
	double x2 = p2->getX();
	double y2 = p2->getY();
	double x3 = p3->getX();
	double y3 = p3->getY();
	double s1 = x1*x1+y1*y1;
	double s2 = x2*x2+y2*y2;
	double s3 = x3*x3+y3*y3;
	double a = determinant(x1, y1, 1, x2, y2, 1, x3, y3, 1);
	double e = determinant(s1, x1, 1, s2, x2, 1, s3, x3, 1);
	return -e/(2*a);
}

double
Arc::determinant(double a1, double a2, double a3, double b1, double b2, double b3, double c1, double c2, double c3) {
	return a1*b2*c3-a1*b3*c2+a2*b3*c1-a2*b1*c3+a3*b1*c2-a3*b2*c1;
}
