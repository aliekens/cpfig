/***************************************************************************
                          figure.h  -  description
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

#ifndef FIGURE_H
#define FIGURE_H


/**This class handles figures, and can output them in .fig format.
  *@author Anthony Liekens
  */

#include "object.h"

#include <vector>
#include <iostream>

class Figure : public std::vector<Object*> {
public:
	/**Enumeration of orientations.
		*The following orientations can be used to set the orientation of a figure object : {\tt Landscape, Portrait}
		*/
	enum Orientations { Landscape = 0, Portrait = 1 };
	
	/**Enumeration of justifications.
		*The following justifications can be used to set the justification of a figure object : {\tt Center, FlushLeft}
		*/
	enum Justifications { Center = 0, FlushLeft = 1 };
	
	/**Enumeration of units.
		*The following units can be used to set the units of a figure object : {\tt Metric, Inches}
		*/
	enum Units { Metric = 0, Inches = 1 };
	
	/**Enumeration of papersizes.
		*The following papersizes can be used to set the papersize of a figure object : {\tt Letter, Legal, Ledger, Tabloid, A, B, C, D, E, A4, A3, A2, A1, A0, B5}
		*/
	enum Papersizes { Letter = 0,
									 Legal = 1,
									 Ledger = 2,
									 Tabloid = 3,
									 A = 4,
									 B = 5,
									 C = 6,
									 D = 7,
									 E = 8,
									 A4 = 9,
									 A3 = 10,
									 A2 = 11,
									 A1 = 12,
									 A0 = 13,
									 B5 = 14 };
									
	/**Enumeration of multiple pages types.
		*The following types can be used to set the multiple page property of a figure object : {\tt Single, Multiple}
		*/
	enum MultiplePages { Single = 0, Multiple = 1 };
	
private:
	Orientations orientation;
	Justifications justification;
	Units units;
	Papersizes papersize;
	float magnification;
	MultiplePages multiplePage;
	int transparentColor;
	int resolution;
	int coordSystem;
	
public:
	/**Constructor.
		*Constructs an empty figure object and sets the figure attributes to their defaults.
		*/
	Figure();
	/**Destructor.
		*Destructs a figure object
		*/
	~Figure();
	
	/**Set the orientation.
		*@param orientation {@link Figure::Orientations Orientations}
		*@return void
		*/
	void setOrientation(Orientations orientation) { this->orientation = orientation; }
	/**Set the justification.
		*@param justification {@link Figure::Justifications Justifications}
		*@return void
		*/
	void setJustification(Justifications justification) { this->justification = justification; }
	/**Set the units.
		*@param units {@link Figure::Units Units}
		*@return void
		*/
	void setUnits(Units units) { this->units = units; }
	/**Set the paper size.
		*@param papersize {@link Figure::Papersizes Papersizes}
		*@return void
		*/
	void setPapersize(Papersizes papersize) { this->papersize = papersize; }
	/**Set the magnification.
		*@param magnification float value
		*@return void
		*/
	void setMagnification (float magnification) { this->magnification = magnification; }
	/**Set the multiple page property.
		*@param multiplePage {@link Figure::MultiplePages MultiplePages}
		*@return void
		*/
	void setMultiplePage (MultiplePages multiplePage) { this->multiplePage = multiplePage; }
	/**Set the transparent color.
		*@param transparentColor integer value
		*@return void
		*/
	void setTransparentColor (int transparentColor) { this->transparentColor = transparentColor; }
	/**Set the resolution.
		*@param resolution integer value
		*@return void
		*/
	void setResolution (int resolution) { this->resolution = resolution; }
	/**Set the coordination system.
		*@param coordSystem integer value
		*@return void
		*/
	void setCoordSystem (int coordSystem) { this->coordSystem = coordSystem; }
	
	/**Returns the orientation.
		*@return {@link Figure::Orientations Orientations}
		*/
	Orientations getOrientation() { return orientation; }
	/**Returns the justification.
		*@return {@link Figure::Justifications Justifications}
		*/
	Justifications getJustification() { return justification; }
	/**Returns the units.
		*@return {@link Figure::Units Units}
		*/
	Units getUnits() { return units; }
	/**Returns the paper size.
		*@return {@link Figure::Papersizes Papersizes}
		*/
	Papersizes getPapersize() { return papersize; }
	/**Returns the magnification.
		*@return float
		*/
	float getMagnification() { return magnification; }
	/**Returns the multiple page property.
		*@return {@link Figure::MultiplePages MultiplePages}
		*/
	MultiplePages getMultiplePage() { return multiplePage; }
	/**Returns the transparent color.
		*@return int
		*/
	int getTransparentColor() { return transparentColor; }
	/**Returns the resolution.
		*@return int
		*/
	int getResolution() { return resolution; }
	/**Returns the coordination system.
		*@return int
		*/
	int getCoordSystem() { return coordSystem; }
	
	/**Write the figure object to a given outstream.
		*@param stream output stream
		*@return void
		*/
	void write(std::ostream &stream) const;
	/**Write an Orientations object to a given outstream.
		*@param stream output stream
		*@param orientations {@link Figure::Orientations Orientations}
		*@return void
		*/
	void write(std::ostream &stream, Orientations orientations) const;
	/**Write a Justifications object to a given outstream.
		*@param stream output stream
		*@param justifications {@link Figure::Justifications Justifications}
		*@return void
		*/
	void write(std::ostream &stream, Justifications justifications) const;
	/**Write a Papersizes object to a given outstream.
		*@param stream output stream
		*@param papersizes {@link Figure::Papersizes Papersizes}
		*@return void
		*/
	void write(std::ostream &stream, Papersizes paparesizes) const;
	/**Write a Units object to a given outstream.
		*@param stream output stream
		*@param papersizes {@link Figure::Units Units}
		*@return void
		*/
	void write(std::ostream &stream, Units units) const;
	/**Write a MultiplePages object to a given outstream.
		*@param stream output stream
		*@param multiplepages {@link Figure::MultiplePages MultiplePages}
		*@return void
		*/
	void write(std::ostream &stream, MultiplePages multiplepages) const;
};
	
inline std::ostream &operator<<(std::ostream &stream, const Figure & f) {
	f.write(stream);
	return stream;
}

#endif
