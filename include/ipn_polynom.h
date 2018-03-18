#ifndef IPN_POLYNOM_H

/*
	Author: reznikovkg
	GitHub: https://github.com/reznikovkg
	Email: kosrez1@yandex.ru

	Project name: Interpolation polinom by Newton
	File name: ipn_polynom.h
	GitHub Repository: https://github.com/reznikovkg/nm-ipN
*/

#define IPN_POLYNOM_H

// class interpolation polinom by Newton
class ipn_Polynom
{
private:
	ipn_Points points;
	int n;
	ipn_Array diff;

public:
	ipn_Polynom() {}
	ipn_Polynom(ipn_Points pPoints) {
		points = pPoints;
		n = points.getN();
		diff = ipn_Array(n, n);
		setDiff();
	}

	double p(double x) {
		return points.getY(1) + pRec(x, 1, n);
	}
	double pRec(double x, int k, int ipn_n) {
		double result = 0;
		if (k < ipn_n) {
			result = diff.getIPNA(0,k);
			result *= pRecProd(x, k);
			result += pRec(x, k + 1, ipn_n);
		}
		return result;
	}
	double pRecProd(double x, int k) {
		double result = 1;
		for (int i = 1; i <= k; i++) {
			result *= (x - points.getX(i));
		}
		return result;
	}

	void printDiff() { diff.printIPNA(); }

	void setDiff() {
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				diff.setIPNA(i,j,getDiffSum(i, j));
			}
		}
	}
	double getDiffSum(int i, int j) {
		double sum = 0;
		for (int sum_j = i; sum_j <= j; sum_j++) {
			sum += (points.getY(sum_j+1) / getDiffProd(sum_j, i, j));
		}
		return sum;
	}
	double getDiffProd(int sum_j, int i, int j) {
		double prod = 1;
		for (int prod_j = i; prod_j <= j; prod_j++) {
			if (prod_j != sum_j) {
				prod *= (points.getX(sum_j+1) - points.getX(prod_j+1));
			}
		}
		return prod;
	}

	~ipn_Polynom() {}
};

#endif IPN_POLYNOM_H
