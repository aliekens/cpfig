/***************************************************************************
                          figure.cpp  -  description
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

#include "figure.h"

Figure::Figure(){
	setOrientation(Landscape);
	setJustification(Center);
	setUnits(Inches);
	setPapersize(Letter);
	setMagnification(100);
	setMultiplePage(Single);
	setTransparentColor(-2);
	setResolution(1200);
	setCoordSystem(2);
}

Figure::~Figure(){
}

void
Figure::write(std::ostream &stream, Orientations o) const {
	switch (o) {
		case Landscape:
			stream << "Landscape\n";
		break;
		case Portrait:
			stream << "Portrait\n";
		break;
	}
}

void
Figure::write(std::ostream &stream, Justifications j) const {
	switch (j) {
		case Center:
			stream << "Center\n";
		break;
		case FlushLeft:
			stream << "Flush Left\n";
		break;
	}
}

void
Figure::write(std::ostream &stream, MultiplePages m) const {
	switch (m) {
		case Single:
			stream << "Single\n";
		break;
		case Multiple:
			stream << "Multiple\n";
		break;
	}
}

void
Figure::write(std::ostream &stream, Units u) const {
	switch (u) {
		case Metric:
			stream << "Metric\n";
		break;
		case Inches:
			stream << "Inches\n";
		break;
	}
}

void
Figure::write(std::ostream &stream, Papersizes p) const {
	switch (p) {
		case Letter:
			stream << "Letter\n";
		break;
		case Legal:
			stream << "Legal\n";
		break;
		case Ledger:
			stream << "Ledger\n";
		break;
		case Tabloid:
			stream << "Tabloid\n";
		break;
		case A:
			stream << "A\n";
		break;
		case B:
			stream << "B\n";
		break;
		case C:
			stream << "C\n";
		break;
		case D:
			stream << "D\n";
		break;
		case E:
			stream << "E\n";
		break;
		case A4:
			stream << "A4\n";
		break;
		case A3:
			stream << "A3\n";
		break;
		case A2:
			stream << "A2\n";
		break;
		case A1:
			stream << "A1\n";
		break;
		case A0:
			stream << "A0\n";
		break;
		case B5:
			stream << "B5\n";
		break;
	}
}

void
Figure::write(std::ostream &stream) const {
	stream << "#FIG 3.2\n";
	write(stream, orientation);
	write(stream, justification);
	write(stream, units);
	write(stream, papersize);
	stream << magnification << "\n";
	write(stream, multiplePage);
	stream << transparentColor << "\n";
	stream << resolution << " " << coordSystem << "\n";
	for (const_iterator i = begin(); i != end(); i++)
		stream << *(*i);
}
