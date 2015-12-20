#include "matrix.h"
#include "iostream"

matrix::matrix()
{

	num_columns = -1;
	num_rows = -1;
}

matrix::matrix(int rows,int columns)
{
	int i,j;

	num_columns = columns;
	num_rows = rows;

	element = new double*[num_rows];

	for (i = 0; i < num_rows; i++)
	{
		element[i] = new double[num_columns];

		for (j = 0; j < num_columns; j++)
		{
			element[i][j] = 0;
		}
	}
	
}

matrix::matrix(matrix& m)
{
	
	int i, j;

	num_columns = m.num_columns;
	num_rows = m.num_rows;

	element = new double*[num_rows];

	for (i = 0; i < num_rows; i++)
	{
		element[i] = new double[num_columns];

		for (j = 0; j < num_columns; j++)
		{
			element[i][j] = m.element[i][j];
		}
	}
}

matrix::~matrix()
{
	int i;

	for (i = 0; i < num_rows; i++)
	{
		delete[] element[i];
	}

	delete[] element;

}

matrix matrix::operator=(const matrix& m)
{
	int i, j;

	num_rows = m.num_rows;
	num_columns = m.num_columns;

	for (i = 0; i < num_rows; i++)
	{
		for (j = 0; j < num_columns; j++)
		{
			element[i][j] = m.element[i][j];
		}
	}

	return *this;
}

matrix matrix::operator+(const matrix &m)
{
	int i, j;
	matrix new_matrix(num_rows, num_columns);

	if ((num_columns != m.num_columns) || (num_rows != m.num_rows))
	{
		cout << "matrixes cannot be added" << endl;
		return *this;
	}

	for (i = 0; i < num_rows; i++)
	{
		for (j = 0; j < num_columns; j++)
		{
			new_matrix.element[i][j] = m.element[i][j] + element[i][j];
		}
	}

	return new_matrix;
}

matrix matrix::operator-(const matrix &m)
{
	int i, j;
	matrix new_matrix(num_rows, num_columns);

	if ((num_columns != m.num_columns) || (num_rows != m.num_rows))
	{
		cout << "matrixes cannot be subtracted" << endl;
		return *this;
	}

	for (i = 0; i < num_rows; i++)
	{
		for (j = 0; j < num_columns; j++)
		{
			new_matrix.element[i][j] = element[i][j] - m.element[i][j];
		}
	}

	return new_matrix;
}

matrix matrix::operator*(const double d)
{
	matrix new_matrix(num_rows, num_columns);
	int i, j;

	for (i = 0; i < num_rows; i++)
	{
		for (j = 0; j < num_columns; j++)
		{
			new_matrix.element[i][j] = d * element[i][j];
		}
	}

	return new_matrix;
}

matrix matrix::operator*(const matrix& m)
{
	int i, j, k;
	matrix new_matrix(num_rows, m.num_columns);

	if (m.num_rows != num_columns)
	{
		cout << "Matrixes cannot be multiplied" << endl;
		return *this;
	}

	for (i = 0; i < new_matrix.num_rows; i++)
	{
		for (j = 0; j < new_matrix.num_columns; j++)
		{
			for (k = 0; k < num_columns;k++)
			{
				new_matrix.element[i][j] += element[i][k] * m.element[k][j];
			}
		}
	}

	return new_matrix;
}

void matrix::printMatrix()
{
	int i, j;

	for (i = 0; i < num_rows; i++)
	{
		for (j = 0; j < num_columns; j++)
		{
			cout << element[i][j] << " ";
		}
		cout << endl;
	}

}