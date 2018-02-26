#define _USE_MATH_DEFINES

double i_func(double x) {
	return x*x + 2 * x + 1;
}

double i_a = -15, i_b = 16;

const int i_n = 3;

double i_table[i_n];

double i_h() {
	return (i_b - i_a) / i_n;
}
void i_set_table() {
	for (int i = 0; i <= i_n; i++)
	{
		i_table[i] = i*i_h();
	}
}

void i_get_table() {
	for (int i = 0; i <= i_n; i++)
	{
		std::cout<<i_table[i] << '\t';
	}
	std::cout << '\n';
}




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