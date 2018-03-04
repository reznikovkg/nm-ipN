/**
	author: reznikovkg
	github: https://github.com/reznikovkg
	email: kosrez1@yandex.ru

	namefile: data.h
	
	target: Initial data
**/

//function interpolation
double ipn_func(double x) {
	return x*x + 2 * x + 1;
}

//interval interpolation
double ipn_a = -15, ipn_b = 16;

//quantity points
const int ipn_n = 7;

//number of points of a polynom
const int ipn_n_poly = 1000;