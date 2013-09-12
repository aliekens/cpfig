#ifndef SCALE3DMATRIX_H
#define SCALE3DMATRIX_H

#include "matrix.h"
#include <math.h>

class
Scale3DMatrix : public Matrix< double > {
public:

	Scale3DMatrix( double xScale, double yScale, double zScale ) : Matrix< double >( 3 ) {
		(*this)[ 0 ][ 0 ] = xScale;
		(*this)[ 1 ][ 1 ] = yScale;
		(*this)[ 2 ][ 2 ] = zScale;
	}
	
	Scale3DMatrix( double scale ) : Matrix< double >( 3 ) {
		(*this)[ 0 ][ 0 ] = scale;
		(*this)[ 1 ][ 1 ] = scale;
		(*this)[ 2 ][ 2 ] = scale;
	}
	
};

#endif
