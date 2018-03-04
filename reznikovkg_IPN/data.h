/**
	author: reznikovkg
	github: https://github.com/reznikovkg
	email: kosrez1@yandex.ru

	namefile: data.h
	
	target: initial data
**/

//function interpolation
double i_func(double x) {
	return x*x + 2 * x + 1;
}

//interval interpolation
double i_a = -15, i_b = 16;

//quantity intervals
const int i_n = 2;