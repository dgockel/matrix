#ifndef MAXRIX_H
#define MATRIX_H

using namespace std;

class matrix
{
public:
	int num_rows, num_columns;
	double **element;

	matrix(); // default constructor
	matrix(int,int); // constructor
	matrix(matrix&); // copy constructor
	~matrix(); // destructor


	void printMatrix(); // prints matrix to screen

	matrix matrix::operator=(const matrix&); // assignment operator
	matrix matrix::operator+(const matrix&); // overloaded addition operator
	matrix matrix::operator-(const matrix&); // overloaded subtraction operator
	matrix matrix::operator*(const matrix&); // overloaded multiply by a matrix
	matrix matrix::operator*(const double); // overloaded multiply by a number

private:

};


#endif