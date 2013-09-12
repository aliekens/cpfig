/***************************************************************************
                          polygon.h  -  description
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

#ifndef POLYGON_H
#define POLYGON_H

#include "polyline.h"

/**This class handles polygons. This class is derived from {@link PolyLine PolyLine}.
  *@author Anthony Liekens
  */

class Polygon : public PolyLine  {
public: 
	Polygon();
	Polygon(Coordinate *, Coordinate *);
	~Polygon();
};

#endif
