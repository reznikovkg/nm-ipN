// interpolation-polinom-Newton.cpp: определяет точку входа для консольного приложения.
//
#include "stdafx.h"
#include <iostream>
#include "IPN_data.h"

using namespace std;

void main()
{
	i_set_table();
	i_get_table();

	for (double ii = i_a; ii <= i_b; ii+=i_h()) {
		cout << ii << '\t' << i_lagrange(i_table, i_h(), i_n, ii) << '\n';
	}

	system("pause");
}