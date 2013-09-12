/***************************************************************************
                          attributes.h  -  description
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

#ifndef ATTRIBUTES_H
#define ATTRIBUTES_H

#include "arrow.h"

/**Generic class to handle the attributes of objects.
  *@author Anthony Liekens
  */

class Attributes {
public:
	/**Enumeration of line styles.
		The following line styles can be used to set the line style of an object : {\tt DefaultLineStyle,
		Solid, Dashed, Dotted, DashDotted, DashDotted, DashDoubleDotted, DashTripleDotted}
		*/
	enum LineStyles { DefaultLineStyle = -1,
										Solid = 0,
										Dashed = 1,
										Dotted = 2,
										DashDotted = 3,
										DashDoubleDotted = 4,
										DashTripleDotted = 5
									};
									
	enum Colors { DefaultColor = -1,
								Black = 0,
								Blue = 1,
								Green = 2,
								Cyan = 3,
								Red = 4,
								Magenta = 5,
								Yellow = 6,
								White = 7,
								Gold = 31 };
								
	/**Enumeration of font faces.
		*The following fonts can be used to set the font face of an object : {\tt DefaultLatex, Roman, Bold, Italic, SansSerif, TypeWriter,
			DefaultPostScript, TimesRoman, TimesItalic, TimesBold, TimesBoldItalic, AvantGardeBook, AvantGardeBookOblique,
			AvantGardeDemi, AvantGardeDemiOblique, BookmanLight, BookmanLightItalic, BookmanDemi, BookmanDemiItalic, Courier,
			CourierOblique, CourierBold, CourierBoldOblique, Helvetica, HelveticaOblique, HelveticaBold, HelveticaBoldOblique,
			HelveticaNarrow, HelveticaNarrowOblique, HelveticaNarrowBold, HelveticaNarrowBoldOblique, NewCenturySchoolbookRoman,
			NewCenturySchoolbookItalic, NewCenturySchoolbookBold, NewCenturySchoolbookBoldItalic, PalatinoRoman, PalatinoItalic,
			PalatinoBold, PalatinoBoldItalic, Symbol, ZapfChanceryMediumItalic, ZapfDingbats}
		*/
	enum Fonts { DefaultLatex = 0,
							 Roman = 1,
							 Bold = 2,
							 Italic = 3,
							 SansSerif = 4,
							 TypeWriter = 5,
							 DefaultPostScript = -1,
							 TimesRoman = 0,
							 TimesItalic = 1,
							 TimesBold = 2,
							 TimesBoldItalic = 3,
							 AvantGardeBook = 4,
							 AvantGardeBookOblique = 5,
							 AvantGardeDemi = 6,
							 AvantGardeDemiOblique = 7,
							 BookmanLight = 8,
							 BookmanLightItalic = 9,
							 BookmanDemi = 10,
							 BookmanDemiItalic = 11,
							 Courier = 12,
							 CourierOblique = 13,
							 CourierBold = 14,
							 CourierBoldOblique = 15,
							 Helvetica = 16,
							 HelveticaOblique = 17,
							 HelveticaBold = 18,
							 HelveticaBoldOblique = 19,
							 HelveticaNarrow = 20,
							 HelveticaNarrowOblique = 21,
							 HelveticaNarrowBold = 22,
							 HelveticaNarrowBoldOblique = 23,
							 NewCenturySchoolbookRoman = 24,
							 NewCenturySchoolbookItalic = 25,
							 NewCenturySchoolbookBold = 26,
							 NewCenturySchoolbookBoldItalic = 27,
							 PalatinoRoman = 28,
							 PalatinoItalic = 29,
							 PalatinoBold = 30,
							 PalatinoBoldItalic = 31,
							 Symbol = 32,
							 ZapfChanceryMediumItalic = 32,
							 ZapfDingbats = 34};
							
	enum FontFlags { Rigid = 1,
									 Latex = 2,
									 RigidLatex = 3,
									 PostScript = 4,
									 RigidPostScript = 5,
									 LatexPostScript = 6,
									 RigidLatexPostScript = 7,
									 Hidden = 8,
									 RigidHidden = 9,
									 LatexHidden = 10,
									 RigidLatexHidden = 11,
									 PostScriptHidden = 12,
									 RigidPostScriptHidden = 13,
									 LatexPostScriptHidden = 14,
									 RigidLatexPostScriptHidden = 15 };
							
	
protected:
	LineStyles lineStyle;
	int thickness;	 				// 1/80 inch
	Colors penColor;
	Colors fillColor;
	int depth;							// enumeration type 1..999
	int penStyle;						// not used
	int areaFill;						// enumeration type, -1 = no fill
	float styleVal;					// 1/80 inch
	int joinStyle;					// enumeration type
	int capStyle;						// enumeration type, only used for POLYLINE
	int radius;							// 1/80 inch, radius of arc-boxes
	int forwardArrowBool;		// 0: off, 1: on
	int backwardArrowBool;	// 0: off, 1: on
	float angle;						// angle of text
	Fonts font;
	float fontSize;					// eniumeration type
	FontFlags fontFlags;		// 0:LaTeX fonts, 1:PostScript fonts
	float height;						// height of font
	float length;						// length of font
	
	Arrow forwardArrow;
	Arrow backwardArrow;
	
public:
	/**Constructor.
		*Sets default values for all attributes.
		*/
	Attributes();
	/**Destructor.
		*/
	~Attributes();
	
	/**Set the linestyle.
		*@param lineStyle {@link Attributes::LineStyles LineStyles}
		*@return void
		*/
	void setLineStyle (LineStyles lineStyle) { this->lineStyle = lineStyle; }
	/**Set the thickness.
		*@param thickness integer value
		*@return void
		*/
	void setThickness (int thickness) { this->thickness = thickness; }
	/**Set the pen color.
		*@param penColor {@link Attributes::Colors Colors}
		*@return void
		*/
	void setPenColor (Colors penColor) { this->penColor = penColor; }
	/**Set the fill color.
		*@param fillColor {@link Attributes::Colors Colors}
		*@return void
		*/
	void setFillColor (Colors fillColor) { this->fillColor = fillColor; }
	/**Set the depth (layer depth).
		*@param depth integer value
		*@return void
		*/
	void setDepth (int depth) { this->depth = depth; }
	/**Set the pen style.
		*@param penStyle integer value
		*@return void
		*/
	void setPenStyle (int penStyle) { this->penStyle = penStyle; }
	/**Set the area fill.
		*@param areaFill integer value
		*@return void
		*/
	void setAreaFill (int areaFill) { this->areaFill = areaFill; }
	/**Set the style value.
		*@param styleVal float value
		*@return void
		*/
	void setStyleVal (float styleVal) { this->styleVal = styleVal; }
	/**Set the join style.
		*@param joinStyle integer value
		*@return void
		*/
	void setJoinStyle (int joinStyle) { this->joinStyle = joinStyle; }
	/**Set the cap style.
		*@param capStyle integer value
		*@return void
		*/
	void setCapStyle (int capStyle) { this->capStyle = capStyle; }
	/**Set the radius.
		*@param radius integer value
		*@return void
		*/
	void setRadius (int radius) { this->radius = radius; }
	/**Set the forward arrow bool value (0 = do not draw an arrow, 1 = draw an arrow).
		*@param forwardArrowBool integer value
		*@return void
		*/
	void setForwardArrowBool (int forwardArrowBool) { this->forwardArrowBool = forwardArrowBool; }
	/**Set the backward arrow bool value (0 = do not draw an arrow, 1 = draw an arrow).
		*@param backwardArrowBool integer value
		*@return void
		*/
	void setBackwardArrowBool (int backwardArrowBool) { this->backwardArrowBool = backwardArrowBool; }
	/**Set the forward arrow.
		*@param forwardArrow {@link Arrow Arrow}
		*@return void
		*/
	void setForwardArrow (Arrow forwardArrow) { this->forwardArrow = forwardArrow; }
	/**Set the backward arrow.
		*@param backwardArrow {@link Arrow Arrow}
		*@return void
		*/
	void setBackwardArrow (Arrow backwardArrow) { this->backwardArrow = backwardArrow; }
	/**Set the angle.
		*@param angle float value
		*@return void
		*/
	void setAngle (float angle) { this->angle = angle; }
	/**Set the font face.
		*@param font {@link Attributes::Fonts Fonts}
		*@return void
		*/
	void setFont (Fonts font) { this->font = font; }
	/**Set the font size.
		*@param fontSize float value
		*@return void
		*/
	void setFontSize (float fontSize) { this->fontSize = fontSize; }
	/**Set the font flags.
		*@param font {@link Attributes::FontFlags FontFlags}
		*@return void
		*/
	void setFontFlags (FontFlags fontFlags) { this->fontFlags = fontFlags; }
	/**Set the font height (of bounding box).
		*@param height float value
		*@return void
		*/
	void setHeight (float height) { this->height = height; }
	/**Set the font length (of bounding box).
		*@param lenght float value
		*@return void
		*/
	void setLength (float length) { this->length = length; }
	/**Set all values of an instance of {@link Attributes Attributes}.
		*@param attributes instance of {@link Attributes Attributes}
		*@return void
		*/
	void setAttributes(Attributes attributes);
	
	/**Returns the line style.
		*@return Instance of {@link Attributes::LineStyles Attributes::LineStyles}
		*/
	LineStyles getLineStyle () { return lineStyle; }
	/**Returns the thickness.
		*@return int
		*/
	int getThickness () { return thickness; }
	/**Returns the pen color.
		*@return Instance of {@link Attributes::Colors Attributes::Colors}
		*/
	Colors getPenColor () { return penColor; }
	/**Returns the fill color.
		*@return Instance of {@link Attributes::Colors Attributes::Colors}
		*/
	Colors getFillColor () { return fillColor; }
	/**Returns the depth (layer depth).
		*@return int
		*/
	int getDepth () { return depth; }
	/**Returns the pen style.
		*@return int
		*/
	int getPenStyle () { return penStyle; }
	/**Returns the area fill.
		*@return int
		*/
	int getAreaFill () { return areaFill; }
	/**Returns the style value.
		*@return float
		*/
	float getStyleVal () { return styleVal; }
	/**Returns the join style.
		*@return int
		*/
	int getJoinStyle () { return joinStyle; }
	/**Returns the cap style.
		*@return int
		*/
	int getCapStyle () { return capStyle; }
	/**Returns the radius.
		*@return int
		*/
	int getRadius () { return radius; }
	/**Returns the forward arrow bool value (0 = do not draw an arrow, 1 = draw an arrow).
		*@return int
		*/
	int getForwardArrowBool () { return forwardArrowBool; }
	/**Returns the backward arrow bool value (0 = do not draw an arrow, 1 = draw an arrow).
		*@return int
		*/
	int getBackwardArrowBool () { return backwardArrowBool; }
	/**Returns the forward arrow.
		*@return Instance of {@link Arrow Arrow}
		*/
	Arrow getForwardArrow () { return forwardArrow; }
	/**Returns the backward arrow.
		*@return Instance of {@link Arrow Arrow}
		*/
	Arrow getBackwardArrow () { return backwardArrow; }
	/**Returns the angle.
		*@return float
		*/
	float getAngle () { return angle; }
	/**Returns the font face.
		*@return Instance of {@link Attributes::Fonts Attributes::Fonts}
		*/
	Fonts getFont () { return font; }
	/**Returns the font size.
		*@return float
		*/
	float getFontSize () { return fontSize; }
	/**Returns the font flags.
		*@return Instance of {@link Attributes::FontFlags Attributes::FontFlags}
		*/
	FontFlags getFontFlags () { return fontFlags; }
	/**Returns the font height (of bounding box).
		*@return float
		*/
	float getHeight () { return height; }
	/**Returns the font length (of bounding box).
		*@return float
		*/
	float getLength () { return length; }
		
	/**Returns itself. This method can be used to extract attributes out of {@link Object Object} instances.
		*@return Instance of {@link Attributes Attributes}
		*/
	Attributes getAttributes() { return (*this); }
};

#endif
