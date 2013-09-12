/***************************************************************************
                         polygon3d.cpp  -  description
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

#include "polygon3d.h"

#include "polygon.h"

Polygon3D::Polygon3D() {
	setCode(Object::PolyLineCode);
	setSubType(PolygonType);
}

Polygon3D::Polygon3D(Coordinate3D *a, Coordinate3D *b) {
	setCode(Object::PolyLineCode);
	setSubType(PolygonType);
	push_back(a);
	push_back(b);
}

Polygon3D::~Polygon3D() {
}

std::pair< double, double > 
Polygon3D::getDepthRange() {

	double minDepth =  5000000;
	double maxDepth = -5000000;
	
	for( iterator i = begin(); i != end(); i++ ) {
		double depth = (*i)->getZ();
		if( depth < minDepth )
			minDepth = depth;
		if( depth > maxDepth )
			maxDepth = depth;
	}
	
	return std::pair< double, double >( minDepth, maxDepth );
	
}

void 
Polygon3D::render( Figure* figure, double xOffset, double yOffset, double scale, double distance, double minDepth, double maxDepth, int minFigDepth, int maxFigDepth ) {

	// determine polygon's depth (average)
	
	double depth = 0;
	for( iterator i = begin(); i != end(); i++ ) {
		depth += (*i)->getZ();
	}
	depth /= size();
	depth = depth - minDepth;
	depth = depth / ( maxDepth - minDepth );
	depth = minFigDepth + depth * ( maxFigDepth - minFigDepth );

	// create the flat polygon

	Polygon* flat = new Polygon();
	
	// let it inherit all properties from this polygon
	
	flat->setLineStyle( getLineStyle() );
	flat->setThickness( getThickness() );
	flat->setPenColor( getPenColor() );
	flat->setFillColor( getFillColor() );
	flat->setDepth( (int)depth );
	flat->setPenStyle( getPenStyle() );
	flat->setAreaFill( getAreaFill() );
	flat->setStyleVal( getStyleVal() );
	flat->setJoinStyle( getJoinStyle() );
	flat->setCapStyle( getCapStyle() );
	flat->setRadius( getRadius() );
	
	// add 2d projections of 3d coordinates to flat polygon
	
	for( iterator i = begin(); i != end(); i++ ) {
		flat->push_back( (*i)->projection( xOffset, yOffset, scale, distance ) );
	}
	
	// put it in our figure
	
	figure->push_back( flat );
	
}

void 
Polygon3D::applyMatrix( Matrix< double >* m ) {

	for( iterator i = begin(); i != end(); i++ ) {
		(*i)->applyMatrix( m );
	}

}

void 
Polygon3D::translate( Coordinate3D* c ) {

	for( iterator i = begin(); i != end(); i++ ) {
		(*i)->translate( c );
	}

}

void
Polygon3D::write(std::ostream &stream) const {
	stream << "# polygon3D\n";
	stream << code << " ";
	stream << subType << " ";
	stream << lineStyle << " ";
	stream << thickness << " ";
	stream << penColor << " ";
	stream << fillColor << " ";
	stream << depth << " ";
	stream << penStyle << " ";
	stream << areaFill << " ";
	stream << styleVal << " ";
	stream << joinStyle << " ";
	stream << capStyle << " ";
	stream << radius << " ";
	if (subType==1) {
		stream << forwardArrowBool << " ";
		stream << backwardArrowBool << " ";
	} else {
		stream << 0 << " " << 0 << " ";
	}
	if (subType==3)
		stream << size()+1 << "\n";
	else
		stream << size() << "\n";
	if (subType==1) {
		if (forwardArrowBool)
			stream << "\t" << forwardArrow;
		if (backwardArrowBool)
			stream << "\t" << backwardArrow;
	}
	stream << "\t";
	for (const_iterator i = begin(); i != end(); i++)
		stream << (*(*i)) << " ";
	if (subType==3)
		stream << (*(*begin())) << " ";
	stream << "\n";
}
