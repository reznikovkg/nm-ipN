// interpolation-polinom-Newton.cpp: ���������� ����� ����� ��� ����������� ����������.
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


	
	system("pause");
}