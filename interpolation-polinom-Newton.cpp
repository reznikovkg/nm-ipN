// interpolation-polinom-Newton.cpp: определяет точку входа для консольного приложения.
//
#include "stdafx.h"
#include <iostream>
#include "reznikovkg_IPN/IPN.h"

using namespace std;

void main()
{
	ipn_set_table_x_fx();

	cout << "GET TABLE X: "; ipn_get_tableX();
	cout << "GET TABLE F: "; ipn_get_tableFx();
	ipn_set_tableDifferences();
	ipn_get_tableDIFF();



	cout << "\nGET TABLE Nn: \n"; 
	for (int i = ipn_a_poly; i <= ipn_b_poly; i+= ipn_h_poly)
	{
		cout << i <<")  " << ipn(i) << '\n';
	}

	
	system("pause");
}