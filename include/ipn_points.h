#ifndef IPN_POINTS_H

/*
	Author: reznikovkg
	GitHub: https://github.com/reznikovkg
	Email: kosrez1@yandex.ru

	Project name: Interpolation polinom by Newton
	File name: ipn_polynom.h
	GitHub Repository: https://github.com/reznikovkg/nm-ipN
*/

#define IPN_POINTS_H

// class interpolation polinom by Newton
class ipn_Points : public ipn_Array
{
private:

public:
	ipn_Points():ipn_Array() {}
	ipn_Points(int pN) :ipn_Array(2, pN) {};

	double getX(int i) { return getIPNA(0, i - 1); } void setX(int i, double k) { setIPNA(0, i - 1,k); }
	double getY(int i) { return getIPNA(1, i - 1); } void setY(int i, double k) { setIPNA(1, i - 1, k); }
	int getN() { return getAj(); }

	~ipn_Points() {}
};

#endif IPN_POINTS_H
