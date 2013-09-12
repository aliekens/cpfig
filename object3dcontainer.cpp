#include "object3dcontainer.h"

#include <map> // i need this for pair<T,T>

std::pair< double, double >
Object3DContainer::getDepthRange() {

	std::pair< double, double > fullRange = std::make_pair( 5000000, -5000000 );
	
	// figure out the range of the needed z buffer
	
	for( iterator i = begin(); i != end(); i++ ) {
		std::pair< double, double > range = (*i)->getDepthRange();
		if( range.first < fullRange.first )
			fullRange.first = range.first;
		if( range.second > fullRange.second )
			fullRange.second = range.second;
	}
	
	return fullRange;

}
	
void
Object3DContainer::render( Figure* figure, double xOffset, double yOffset, double scale, double distance, double minRange, double maxRange, int minFigDepth, int maxFigDepth ) {

	std::pair< double, double > range = getDepthRange();
	
	// render the objects
	
	for( iterator i = begin(); i != end(); i++ )
		(*i)->render( figure, xOffset, yOffset, scale, distance, range.first, range.second, minFigDepth, maxFigDepth );
	
}

void
Object3DContainer::applyMatrix( Matrix< double >* m ) {
	for( iterator i = begin(); i != end(); i++ )
		(*i)->applyMatrix( m );
}

void
Object3DContainer::translate( Coordinate3D* c ) {
	for( iterator i = begin(); i != end(); i++ )
		(*i)->translate( c );
}

