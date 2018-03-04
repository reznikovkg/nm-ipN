/**
	project: Interpolation polinom by Newton
	author: reznikovkg
	github: https://github.com/reznikovkg
	email: kosrez1@yandex.ru

	namefile: input_data.h
	
	target: Input data. 
	Function, interval functions, quantity points.
	Number of points of a polynom, interval interpolation polynom.
**/


//initial function 
double ipn_func(double x) {
	return x*x + 1;
}

//interval function
const double ipn_a = -5, ipn_b = 5;

//quantity points
const int ipn_n = 3;


//number of points of a polynom
const int ipn_n_poly = 11;

//interval interpolation polynom
const double ipn_a_poly = -10, ipn_b_poly = 10;