/**
	project: Interpolation polinom by Newton
	author: reznikovkg
	github: https://github.com/reznikovkg
	email: kosrez1@yandex.ru

	namefile: global_properties.h

	target: Creation of main global functions
**/

//step of the initial function
double ipn_h = (ipn_b - ipn_a) / (ipn_n - 1);

//array values of axis of abscissa in increments
double ipn_table_x[ipn_n];

//array values of axis of ordinates of corresponding for abscissa
double ipn_table_fx[ipn_n];



double ipn_h_poly = (ipn_b_poly - ipn_a_poly) / (ipn_n_poly - 1);

double ipn_table_differences[ipn_n][ipn_n];

double ipn_table_polynom[ipn_n_poly];