/***************************************************************************
                          box.h  -  description
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

#ifndef BOX_H
#define BOX_H

#include "polyline.h"

/**This class handles box objects. This class is derived from {@link PolyLine PolyLine}.
  *@author Anthony Liekens
  */

class Box : public PolyLine  {
public:
	/**Constructor.
		*Constructs a box object.
		*/
	Box();
	/**Constructor.
		*Constructs a box object.
		*@param coordinate1 One corner of the box
		*@param coordinate2 Opposite corner of the box
		*/
	Box(Coordinate *coordinate1, Coordinate *coordinate2);
	/**Destructor.
		*Destructs a box object.
		*/
	~Box();
};

#endif
