double i_table[i_n];

double i_h() {
	return (i_b - i_a) / i_n;
}
void i_set_tableX() {
	for (int i = 0; i <= i_n; i++)
	{
		i_table[i] = i*i_h();
	}
}

void i_get_tableX() {
	for (int i = 0; i <= i_n; i++)
	{
		std::cout << i_table[i] << '\t';
	}
	std::cout << '\n';
}

void i_get_tableF() {
	for (int i = 0; i <= i_n; i++)
	{
		std::cout << i_func(i_table[i]) << '\t';
	}
	std::cout << '\n';
}




double i_different_p1(double xi, double xj) {
	return (i_func(xj) - i_func(xi)) / (xj - xi);
}

double i_different(double * xi) {
	return xi[0] + xi[1] + xi[2];
}