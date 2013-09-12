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

#include <iostream>
#include <stdlib.h>

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

int main(int argc, char *argv[])
{
	Figure f;

	// get some coordinates ready to use in a lot of objects
	
	Coordinate *a = new Coordinate (500,500);
	Coordinate *b = new Coordinate (1500,1500);

	// draw a polyline

	PolyLine *polyline = new PolyLine(a, b);
	polyline->push_back(new Coordinate(2000,1500));
	polyline->setLineStyle(Attributes::Dotted);
	
	// give the polyline arrows
	
	Arrow arr;
	arr.setType(Arrow::ClosedPointed);
	arr.setStyle(Arrow::Filled);

	polyline->setBackwardArrowBool(1);
	polyline->setBackwardArrow(arr);
	
	polyline->setForwardArrowBool(1);
	polyline->setForwardArrow(arr);
	
	// polyline is ready, keep it in the fig
	
	f.push_back(polyline);
	
	// an example box using the same coordinates

	Box *box = new Box(a, b);
	box->setThickness(2);
	f.push_back(box);
	
	// an ellipse in that box

	RadiiEllipse *re = new RadiiEllipse(new Coordinate(1000, 1000), new Coordinate(500, 200));
	f.push_back(re);
	
	// another ellipse in that box

	DiameterEllipse *de = new DiameterEllipse(new Coordinate(500, 800), new Coordinate(1500, 1200));
	f.push_back(de);
	
	// a circle defined by a radius, in the box

	RadiusCircle *rc = new RadiusCircle(new Coordinate(1000, 1000), 500);
	f.push_back(rc);
	
	// a circle defined by two points defining its radius

	DiameterCircle *dc = new DiameterCircle(a, b);
	f.push_back(dc);
	
	// some text

	Text* text = new Text(new Coordinate(1900, 900), "fig++");
	text->setFontSize(50);
	f.push_back(text);

	// an arc defined by its three defining points
	// first point comes first

	Arc* arc = new Arc(new Coordinate(1000, 1000), new Coordinate(2000, 1000), new Coordinate(2000, 2000));
	f.push_back(arc);
	
	// this is what's useful: putting something on an arbitrary place

	for (float x = 0; x <= 314; x=x+19.625) {
		PolyLine *l = 
			new PolyLine( 
				new Coordinate(
					(int)(1500.0+500.0*cos(x/100)),
					(int)(1500.0+500.0*sin(x/100))
				),
				new Coordinate(
					(int)(1500.0+1000.0*cos(x/100)),
					(int)(1500.0+1000.0*sin(x/100))
				)
			);
		l->setForwardArrowBool(1);
		arr.setType(Arrow::ClosedIntended);
		l->setForwardArrow(arr);
		f.push_back(l);
	}
	
	// a vector of coordinates

	std::vector<Coordinate *> vc;

	vc.push_back( new Coordinate (2500, 500) );
	vc.push_back( new Coordinate (3000, 500) );
	vc.push_back( new Coordinate (3000, 1000) );
	vc.push_back( new Coordinate (3500, 1000) );
	vc.push_back( new Coordinate (3500, 1500) );
	vc.push_back( new Coordinate (3000, 1500) );
	vc.push_back( new Coordinate (3000, 2000) );
	vc.push_back( new Coordinate (2500, 2000) );
	vc.push_back( new Coordinate (2500, 1500) );
	vc.push_back( new Coordinate (2000, 1500) );
	vc.push_back( new Coordinate (2000, 1000) );
	vc.push_back( new Coordinate (2500, 1000) );
	
	// the vector as a polyline

	Polygon *pl = new Polygon ();
	for (std::vector<Coordinate *>::iterator i = vc.begin(); i != vc.end(); i++)
		pl->push_back(*i);
	f.push_back(pl);
	
	// two possible splines defined by the vector

	Spline *spline1 = new Spline();
	Spline *spline2 = new Spline();
	for (std::vector<Coordinate *>::iterator i = vc.begin(); i != vc.end(); i++) {
		spline1->push_back( new SplineCoordinate(*i, -1) ); // interpolated
		spline2->push_back( new SplineCoordinate(*i, 1) ); //approximated
	}
	spline1->setSubType(Spline::Closed);
	f.push_back(spline1);
	spline2->setSubType(Spline::Closed);
	f.push_back(spline2);
	
	// print the file to the standard out

	std::cout << f;

	return EXIT_SUCCESS;
}
