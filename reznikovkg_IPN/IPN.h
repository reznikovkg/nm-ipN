/**
	author: reznikovkg
	github: https://github.com/reznikovkg
	email: kosrez1@yandex.ru

	namefile: IPN.h
	more info: Interpolation polinom Newton, method divided differences

	target: Run mini-library 
**/

#include "data.h";
#include "main_function.h";



/*
double i_lagr_p(int i, int j, int none) {
	if (j != none) {
		return ();
	}
	else {
		return 1;
	}
}

double i_lagr_s(double x, double last_x = i_b) {
	if (x <= last_x) {
		return i_table[x];
	}
	else {
		return 1;
	}
}
*/
double i_lagrange(double* table,double h, short n, double _x)
{
	double result = 0.0;
	for (short i = 0; i < n; i++)
	{
		double P = 1.0;
		for (short j = 0; j < n; j++)
			if (i != j)
				P *= (_x - i_a - h* j) / h / (i - j);
		result += P* table[i];
	}
	return result;
}