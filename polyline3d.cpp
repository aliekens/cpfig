/***************************************************************************
                         polyline3d.cpp  -  description
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

#include "polyline3d.h"

#include "polyline.h"

PolyLine3D::PolyLine3D() {
	setCode(Object::PolyLineCode);
	setSubType(PolyLine3DType);
}

PolyLine3D::PolyLine3D(Coordinate3D *a, Coordinate3D *b) {
	setCode(Object::PolyLineCode);
	setSubType(PolyLine3DType);
	push_back(a);
	push_back(b);
}

PolyLine3D::~PolyLine3D() {
}

std::pair< double, double > 
PolyLine3D::getDepthRange() {

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
PolyLine3D::render( Figure* figure, double xOffset, double yOffset, double scale, double distance, double minDepth, double maxDepth, int minFigDepth, int maxFigDepth ) {

	// determine polyLine's depth (average)
	
	double depth = 0;
	for( iterator i = begin(); i != end(); i++ ) {
		depth += (*i)->getZ();
	}
	depth /= size();
	depth = depth - minDepth;
	depth = depth / ( maxDepth - minDepth );
	depth = minFigDepth + depth * ( maxFigDepth - minFigDepth );

	// create the flat polyLine

	PolyLine* flat = new PolyLine();
	
	// let it inherit all properties from this polyLine
	
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
	flat->setForwardArrowBool( forwardArrowBool );
	if( forwardArrowBool ) 
		flat->setForwardArrow( getForwardArrow() );
	flat->setBackwardArrowBool( backwardArrowBool );
	if( backwardArrowBool ) 
		flat->setBackwardArrow( getBackwardArrow() );
	
	// add 2d projections of 3d coordinates to flat polyLine
	
	for( iterator i = begin(); i != end(); i++ ) {
		flat->push_back( (*i)->projection( xOffset, yOffset, scale, distance ) );
	}
	
	// put it in our figure
	
	figure->push_back( flat );
	
}

void 
PolyLine3D::applyMatrix( Matrix< double >* m ) {

	for( iterator i = begin(); i != end(); i++ ) {
		(*i)->applyMatrix( m );
	}

}

void 
PolyLine3D::translate( Coordinate3D* c ) {

	for( iterator i = begin(); i != end(); i++ ) {
		(*i)->translate( c );
	}

}

void
PolyLine3D::write(std::ostream &stream) const {
	stream << "# polyline3D\n";
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
