#ifndef OBJECT3D_H
#define OBJECT3D_H

#include "object.h"
#include "figure.h"
#include "matrix.h"

#include "coordinate3d.h"

#include <map> // i need this for pair<T,T>

class Object3D : public Object {
public:

	// Return the range of Z values of the object. We need this to determine
	// the Z range of whole sets of objects, so that these Z values can be
	// scaled to valid values in the 0..999 depth range used by xfig.
	virtual std::pair< double, double> getDepthRange() = 0;
	
	virtual void render( Figure*, double xOffset, double yOffset, double scale, double distance, double minDepth, double maxDepth, int minFigDepth = 0, int maxFigDepth = 999 ) = 0;
	
	virtual void applyMatrix( Matrix< double >* ) = 0;
	virtual void translate( Coordinate3D* ) = 0;
	
};

#endif
