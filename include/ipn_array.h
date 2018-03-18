#ifndef IPN_ARRAY_H

/*
	Author: reznikovkg
	GitHub: https://github.com/reznikovkg
	Email: kosrez1@yandex.ru

	Project name: Interpolation polinom by Newton
	File name: ipn_array.h
	GitHub Repository: https://github.com/reznikovkg/nm-ipN
*/

#define IPN_ARRAY_H

#include <iostream>

using namespace std;

//class array for points on decard system [or other, not problem]
class ipn_Array
{
private:

	double** ipnA;
	int Ai;
	int Aj;

public:
	ipn_Array() {}

	ipn_Array(int ai, int aj) {
		Ai = ai; Aj = aj;

		ipnA = new double*[Ai];
		for (int i = 0; i < Ai; i++) {
			ipnA[i] = new double[Aj];
		}
	}

	double getIPNA(int ai, int aj) { return this->ipnA[ai][aj]; }
	int getAi() { return this->Aj; }
	int getAj() { return this->Aj; }

	void setIPNA(int ai, int aj, double ak) { ipnA[ai][aj] = ak; }

	void printIPNA() {
		for (int i = 0; i < Ai; i++) {
			for (int j = 0; j < Aj; j++) {
				cout << "[" << i << "][" << j << "] = " << ipnA[i][j] << "    ";
			}
			cout << '\n';
		}
	}
	~ipn_Array() {}
};

#endif IPN_ARRAY_H
