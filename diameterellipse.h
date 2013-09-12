/***************************************************************************
                          diameterellipse.h  -  description
                             -------------------
    begin                : Tue Sep 5 2000
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

#ifndef DIAMETERELLIPSE_H
#define DIAMETERELLIPSE_H

#include <math.h>

#include "ellipse.h"

/**This class handles ellipses defined by their bounding box. This class is derived from {@link Ellipse Ellipse}.
  *@author Anthony Liekens
  */

class DiameterEllipse : public Ellipse  {
public: 
	DiameterEllipse();
	DiameterEllipse(Coordinate *, Coordinate *);
	~DiameterEllipse();
};

#endif
