/***************************************************************************
                          main.cpp  -  description
                             -------------------
    begin                : Mon Sep  4 14:40:00 GMT 2000
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

#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include <iostream>
#include <fstream>
#include <stdlib.h>

#include <cpfig/polyline3d.h>
#include <cpfig/object3dcontainer.h>

#include <cpfig/polyline.h>
#include <cpfig/coordinate.h>
#include <cpfig/figure.h>
#include <cpfig/arrow.h>
#include <cpfig/box.h>
#include <cpfig/polygon.h>
#include <cpfig/radiiellipse.h>
#include <cpfig/diameterellipse.h>
#include <cpfig/radiuscircle.h>
#include <cpfig/diametercircle.h>
#include <cpfig/text.h>
#include <cpfig/arc.h>
#include <cpfig/splinecoordinate.h>
#include <cpfig/spline.h>

#include <cpfig/polygon3d.h>
#include <cpfig/object3dcontainer.h>
#include <cpfig/rotation3dmatrix.h>

#define pi 3.1415

int main(int argc, char *argv[])
{

	std::ifstream ifs( "tiefighter.data" );
	
	std::vector< Coordinate3D > coords;
	
	double x, y, z;
	
	do {
	
		ifs >> x;
		if( x != -1 ) {
			ifs >> y >> z;
		}
		coords.push_back( Coordinate3D( x, y, z ) );
		
	} while( x != -1 );
	
	std::cerr << coords.size() << " vertices" << std::endl; 

	Figure* f = new Figure();
	
	Object3DContainer* objects = new Object3DContainer();

	int p;
	do {
		Polygon3D* pl = new Polygon3D();
		ifs >> p;
		if( p != -1 ) {
			pl->push_back( new Coordinate3D( coords[ p ].getX(), coords[ p ].getY(), coords[ p ].getZ() ) );
			int d;
			ifs >> d;
			while( d != -1 ) {
				pl->push_back( new Coordinate3D( coords[ d ].getX(), coords[ d ].getY(), coords[ d ].getZ() ) );
				ifs >> d;
			}
			pl->setAreaFill( 10 );
			pl->setThickness( 1 );
			pl->setCapStyle( 1 );
			pl->setJoinStyle( 1 );
			objects->push_back( pl );
		}
	} while( p != -1 );
	
	std::cerr << objects->size() << " polygons" << std::endl;
	
	objects->applyMatrix( new Rotation3DMatrix( -pi/2, pi/10, pi/10 ) );
	objects->render( f, 0, 0, 100000, 500 );
	
	// output it to stdout

	std::cout << (*f);

	return EXIT_SUCCESS;
}
