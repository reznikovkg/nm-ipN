/**
	project: Interpolation polinom by Newton
	author: reznikovkg
	github: https://github.com/reznikovkg
	email: kosrez1@yandex.ru

	namefile: global_functions.h

	target: 
**/

void ipn_set_table_x_fx() {
	ipn_table_x[0] = ipn_a; ipn_table_fx[0] = ipn_func(ipn_table_x[0]);
	ipn_table_x[ipn_n - 1] = ipn_b; ipn_table_fx[ipn_n - 1] = ipn_func(ipn_table_x[ipn_n - 1]);

	for (int i = 1; i < ipn_n - 1; i++) {
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
void ipn_get_tableDIFF() {
	for (int i = 0; i < ipn_n; i++)
	{
		for (int j = i + 1; j < ipn_n; j++)
		{
			std::cout << ipn_table_differences[i][j] << '\t';
		}
		std::cout << '\n';
	}
	std::cout << '\n';
}



double ipn_set_tableDifferences_prod(int sum_j, int i, int j) {
	double prod = 1;
	for (int prod_j = i;prod_j <= j;prod_j++) {
		if (prod_j != sum_j) {
			prod *= (ipn_table_x[sum_j] - ipn_table_x[prod_j]);
		}
	}
	return prod;
}
double ipn_set_tableDifferences_sum(int i, int j) {
	double sum = 0;
	for (int sum_j = i; sum_j <= j;sum_j++) {
		sum += (ipn_table_fx[sum_j] / ipn_set_tableDifferences_prod(sum_j, i, j));
	}
	return sum;
}
void ipn_set_tableDifferences() {
	for (int i = 0;i < ipn_n;i++) {
		for (int j = i + 1; j < ipn_n;j++) {
			ipn_table_differences[i][j] = ipn_set_tableDifferences_sum(i, j);
		}
	}
}


double ipn_rec_prod(int x, int k) {
	double result = 1;
	for (int i = 0;i < k;i++) {
		result *= (x - ipn_table_x[i]);
	}
	return result;
}

double ipn_rec(int x, int k, int ipn_n) {
	double result = 0;

	if (k < ipn_n) {
		result = ipn_table_differences[0][k];
		result *= ipn_rec_prod(x, k);
		result += ipn_rec(x, k + 1, ipn_n);
	}
	return result;
}

double ipn(double x) {
	return ipn_table_fx[0] + ipn_rec(x, 1, ipn_n);
}