#ifndef OBJECT3DCONTAINER_H
#define OBJECT3DCONTAINER_H

#include "object3d.h"
#include "coordinate3d.h"
#include "figure.h"
#include "matrix.h"

#include <vector>

class Object3DContainer : public Object3D, public std::vector< Object3D* > {
public:
	std::pair< double, double > getDepthRange();
	void render( Figure*, double xOffset, double yOffset, double scale, double distance, double minRange = 0, double maxRange = 0, int minFigDepth = 0, int maxFigDepth = 999 );
	void applyMatrix( Matrix< double >* m );
	void translate( Coordinate3D* );
};

#endif
