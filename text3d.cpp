/***************************************************************************
                         text3d.cpp  -  description
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

#include "text3d.h"

Text3D::Text3D() {
	setCode(Object::TextCode);
	setJustification(Text::LeftJustified);
}

Text3D::Text3D(Coordinate3D *place, std::string text) {
	setCode(Object::TextCode);
	setJustification(Text::LeftJustified);
	this->place = place;
	this->contents = text;
}

Text3D::~Text3D() {
}

std::pair< double, double> 
Text3D::getDepthRange() {

	double depth = place->getZ();
	return std::make_pair( depth, depth );
	
}

void 
Text3D::render( Figure* f, double xOffset, double yOffset, double scale, double distance, double minDepth, double maxDepth, int minFigDepth, int maxFigDepth ) {

	double depth = place->getZ();
	depth = depth - minDepth;
	depth = depth / ( maxDepth - minDepth );
	depth = minFigDepth + depth * ( maxFigDepth - minFigDepth );
	
	Text* text2d = new Text( place->projection( xOffset, yOffset, scale, distance ), contents );
	text2d->setAttributes( (Attributes)(*this) );
	text2d->setJustification( getJustification() );
	text2d->setDepth( (int)depth );
	f->push_back( text2d );

}

void 
Text3D::applyMatrix( Matrix< double >* matrix ) {
	place->applyMatrix( matrix );
}

void 
Text3D::translate( Coordinate3D* c ) {
	place->translate( c );
}

void
Text3D::write(std::ostream &stream) const {
	stream << "# text\n";
	stream << code << " ";
	stream << justification << " ";
	stream << penColor << " ";
	stream << depth << " ";
	stream << penStyle << " ";
	stream << font << " ";
	stream << fontSize << " ";
	stream << angle << " ";
	stream << fontFlags << " ";
	stream << height << " ";
	stream << length << " ";
	stream << *place << " ";
	stream << contents << "\\001\n";
}
