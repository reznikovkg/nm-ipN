// interpolation-polinom-Newton.cpp: определяет точку входа для консольного приложения.
//
#include "stdafx.h"
#include <iostream>
#include "reznikovkg_IPN/IPN.h"

using namespace std;

void main()
{
	i_set_tableX();

	cout << "GET TABLE X: "; i_get_tableX();
	cout << "GET TABLE F: "; i_get_tableF();


	
	system("pause");
}