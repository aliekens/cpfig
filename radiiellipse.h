/***************************************************************************
                          radiiellipse.h  -  description
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

#ifndef RADIIELLIPSE_H
#define RADIIELLIPSE_H

#include "ellipse.h"

/**This class handles ellipses defined by their center and radii. This class is derived from {@link Ellipse Ellipse}.
  *@author Anthony Liekens
  */

class RadiiEllipse : public Ellipse {
public: 
	RadiiEllipse();
	RadiiEllipse(Coordinate *, Coordinate *);
	~RadiiEllipse();
};

#endif
