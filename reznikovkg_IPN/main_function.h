/**
author: reznikovkg
github: https://github.com/reznikovkg
email: kosrez1@yandex.ru

namefile: main_function.h

target: Creation of main global functions
**/




/*
class ipn_poly
{
private:
	double ipn_a, ipn_b, ipn_n;

public:
	ipn_poly(double a, double b, double n) {
		ipn_setParam(a, b, n);
	}

	void ipn_setParam(double a, double b, double n) {
		ipn_a = a;
		ipn_b = b;
		ipn_n = n;
	}

private:
};
*/

//

double ipn_h = (ipn_b - ipn_a) / (ipn_n - 1);

double ipn_table_x[ipn_n];
double ipn_table_fx[ipn_n];

double ipn_table_differences[ipn_n][ipn_n];

double ipn_table_polynom[ipn_n_poly];




void ipn_set_table_x_fx() {
	ipn_table_x[0] = ipn_a;
	ipn_table_x[ipn_n - 1] = ipn_b;

	for (int i = 1; i < ipn_n-1; i++) {
		ipn_table_x[i] = ipn_table_x[0] + i*ipn_h;
		ipn_table_fx[i] = ipn_func(ipn_table_x[i]);
	}
}
void ipn_get_tableX() {
	for (int i = 0; i < ipn_n; i++)
	{
		std::cout << ipn_table_x[i] << '\t';
	}
	std::cout << '\n';
}
void ipn_get_tableFx() {
	for (int i = 0; i < ipn_n; i++)
	{
		std::cout << ipn_table_fx[i] << '\t';
	}
	std::cout << '\n';
}





double ipn_set_tableDifferences_prod(int sum_j, int xj, int i, int j) {
	double prod = 1;
	for (int prod_j = i;prod_j < j;prod_j++) {
		if (prod_j != sum_j) {
			prod *= (ipn_table_x[sum_j] - ipn_table_x[prod_j]);
		}
	}
	return prod;
}

double ipn_set_tableDifferences_sum(int i, int j) {
	double sum = 0;
	for (int sum_j = i; sum_j < j;sum_j++) {
		sum += ipn_table_fx[sum_j] / ipn_set_tableDifferences_prod(sum_j, ipn_table_x[sum_j], i, j);
	}
	return sum;
}

void ipn_set_tableDifferences() {
	for (int i=0;i < ipn_n;i++) {
		for (int j = 1; j <= ipn_n;j++) {
			ipn_table_differences[i][j] = ipn_set_tableDifferences_sum(i,j);
		}
	}
}





/*
double ipn_different_p1(double xi, double xj) {
	return (ipn_func(xj) - ipn_func(xi)) / (xj - xi);
}

double ipn_different(double * xi) {
	double sum
	for (int i = 0; i < ipn_n; i++)
	{

	}
	return 0;
}

double ipn_different_prod() {
	return 0;
}*/