#ifndef MATRIX_H
#define MATRIX_H

#include <vector>
#include <iostream>
using namespace std;

template< class T >
class Matrix : public std::vector< std::vector < T > > {
public:
	Matrix();
	Matrix( const int& );
	Matrix( const int&, const int& );
	
	std::vector< T > operator*( const std::vector< T >& ) const;
	std::vector< T > getColumn( const int ) const;
	Matrix< T > operator*( const Matrix< T >& ) const;
	
	void print();
};

// construct matrix with 1 element
template< class T >
Matrix< T >::Matrix() {
	Matrix< T >::clear();
	std::vector< T > row;
	T element;
	row.push_back( element );
	push_back( row );
}

// construct square matrix
template< class T >
Matrix< T >::Matrix( const int& size ) {
	Matrix< T >::clear();
	for( int y = 0; y < size; y++ ) {
		std::vector< T > row;
		for( int x = 0; x < size; x++ ) {
			T element = ( T )0;
			if( x == y )
				element = ( T )1;
			row.push_back( element );
		}
		push_back( row );
	}
}

// construct any size matrix
template< class T >
Matrix< T >::Matrix( const int& ySize, const int& xSize ) {
	Matrix< T >::clear();
	for( int y = 0; y < ySize; y++ ) {
		std::vector< T > row;
		for( int x = 0; x < xSize; x++ ) {
			T element = ( T )0;
			row.push_back( element );
		}
		push_back( row );
	}
}

// get a certain column
template <class T>
std::vector< T >
Matrix< T >::getColumn( const int column ) const {
	std::vector< T > result;
	for( typename Matrix< T >::const_iterator i = Matrix< T >::begin(); i != Matrix< T >::end(); i++ )
		result.push_back( (*i)[ column ] );
	return result;
}

// product of matrix and vector
template< class T >
std::vector< T > 
Matrix< T >::operator*( const std::vector< T >& v ) const {
	typename std::vector< T > resultVector;
	if( v.size() != (*this)[0].size() ) {
		std::cerr << "Matrix and vector sizes don't match";
		exit( 1 );
	}
	
	for( typename Matrix< T >::const_iterator matrixRow = Matrix< T >::begin(); matrixRow != Matrix< T >::end(); matrixRow++ ) {
		T resultElement = ( T )0;
		typename std::vector< T >::const_iterator vectorElement = v.begin();
		for( typename std::vector< T >::const_iterator matrixElement = matrixRow->begin(); matrixElement != matrixRow->end(); matrixElement++ ) {
			resultElement += *matrixElement * *vectorElement;
			vectorElement++;
		}
		resultVector.push_back( resultElement );
	}
	return resultVector;
}

// product of matrices
template< class T >
Matrix< T > 
Matrix< T >::operator*( const Matrix< T >& otherMatrix ) const {
	Matrix< T > resultMatrix = otherMatrix;
	if( otherMatrix.size() != Matrix< T >::size() ) {
		std::cerr << "Matrix sizes don't match";
		exit( 1 );
	}
	
	for( unsigned int row = 0; row < Matrix< T >::size(); row++ ) 
	for( unsigned int col = 0; col < Matrix< T >::size(); col++ ) {
		resultMatrix[ row ][ col ] = 0;;
		for( unsigned int i = 0; i < Matrix< T >::size(); i++ ) {
			resultMatrix[ row ][ col ] += (*this)[ row ][ i ] * otherMatrix[ i ][ col ];
		}
	}

	return resultMatrix;
}

#endif
