#include <iostream>
#include "matrix.h"

using namespace std;

int main()
{

	matrix **a;

	a = new matrix*[5];
	
	for (int i = 0; i < 5; i++)
	{
		a[i] = new matrix(3, 3);
	}

	a[3]->printMatrix();


	getchar();
	return 4;
}