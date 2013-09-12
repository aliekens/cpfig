#ifndef ROTATION3DMATRIX_H
#define ROTATION3DMATRIX_H

#include "matrix.h"
#include <math.h>

class
Rotation3DMatrix : public Matrix< double > {
public:
	Rotation3DMatrix( double xCorner, double yCorner, double zCorner ) : Matrix< double >( 3 ) {
		(*this)[ 0 ][ 0 ] = cos( zCorner ) * cos( yCorner );
		(*this)[ 0 ][ 1 ] = sin( zCorner ) * cos( yCorner );
		(*this)[ 0 ][ 2 ] = -sin( yCorner );
		(*this)[ 1 ][ 0 ] = ( sin( xCorner ) * sin( yCorner ) * cos( zCorner ) ) - ( cos( xCorner ) * sin( zCorner ) );
		(*this)[ 1 ][ 1 ] = ( sin( xCorner ) * sin( yCorner ) * sin( zCorner ) ) + ( cos( xCorner ) * cos( zCorner ) );
		(*this)[ 1 ][ 2 ] = sin( xCorner ) * cos( yCorner );
		(*this)[ 2 ][ 0 ] = ( cos( xCorner ) * sin( yCorner ) * cos( zCorner ) ) + ( sin( xCorner ) * sin( zCorner ) );
		(*this)[ 2 ][ 1 ] = ( cos( xCorner ) * sin( yCorner ) * sin( zCorner ) ) - ( sin( xCorner ) * cos( zCorner ) );
		(*this)[ 2 ][ 2 ] = cos( xCorner ) * cos( yCorner );
	}
};

#endif
