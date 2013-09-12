/***************************************************************************
                          radiuscircle.h  -  description
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

#ifndef RADIUSCIRCLE_H
#define RADIUSCIRCLE_H

#include "ellipse.h"

/**This class handles circles defined by their center and radius. This class is derived from {@link Ellipse Ellipse}.
  *@author Anthony Liekens
  */

class RadiusCircle : public Ellipse  {
public: 
	RadiusCircle();
	RadiusCircle(Coordinate *, int);
	~RadiusCircle();
};

#endif
