#ifndef POLYLINE3D_H
#define POLYLINE3D_H

#include <vector>

#include "polyline.h"

#include "object3d.h"
#include "coordinate3d.h"

#include <map> // I need this for pair<T,T>

class PolyLine3D : public Object3D, public std::vector<Coordinate3D *> {
public:
	/**Enumeration of polyline types.
		The following types can be used to set the type of a polyline object : {\tt PolyLineType, BoxType, PolygonType, PictureType}.
		Inherited polyline classes will set their appropriate type.
		*/
	enum SubTypes {PolyLine3DType =  1, BoxType = 2, PolygonType = 3, ArcBoxType = 4, PictureType = 5};
private:
	SubTypes subType;
protected:
	/**Set the sub type
		*@param subType {@link PolyLine3D::SubTypes SubTypes}
		*@return void
		*/
	void setSubType (SubTypes subType) { this->subType = subType; }
public:
	/**Constructor. Constructs a polyline object
		*/
	PolyLine3D();
	/**Constructor. Constructs a polyline object with 2 points
		*@param point1 - Instance of {@link Coordinate3D Coordinate3D}. Coordinate3D of the first point
		*@param point2 - Instance of {@link Coordinate3D Coordinate3D}. Coordinate3D of the second point
		*/
	PolyLine3D(Coordinate3D *point1, Coordinate3D *point2);
	/**Destructor. Destructs a polyline object
		*/
	~PolyLine3D();
	
	/**Returns the polyline sub type
		*@return Instance of {@link PolyLine3D::SubTypes SubTypes}
		*/
	int getSubType () { return subType; }
	
	std::pair< double, double > getDepthRange();
	void applyMatrix( Matrix< double >* );
	void render( Figure*, double xOffset, double yOffset, double scale, double distance, double minDepth, double maxDepth, int minFigDepth = 0, int maxFigDepth = 999 );
	void translate( Coordinate3D* );
	
	/**Write the polyline object to a given outstream.
		*@param stream output stream
		*@return void
		*/
	void write(std::ostream &stream) const;
};
	
inline std::ostream &operator<<(std::ostream &stream, const PolyLine3D & p) {
	p.write(stream);
	return stream;
}

#endif
