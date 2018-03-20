#ifndef NM_IPN_CLASS_H

/*
	Author: reznikovkg
	GitHub: https://github.com/reznikovkg
	Email: kosrez1@yandex.ru

	File: nm-ipN-class.h
	GitHub Repository: https://github.com/reznikovkg/nm-ipN
*/

#define NM_IPN_CLASS_H

// class interpolation polinom by Newton
class ipn_Polynom
{
private:
	nm_Points points;
	int n;
	nm_Array diff;

public:
	ipn_Polynom() {}
	ipn_Polynom(nm_Points pPoints) {
		points = pPoints;
		n = points.getN();
		diff = nm_Array(n, n);
		setDiff();
	}

	double p(double x) {
		return points.getY(1) + pRec(x, 1, n);
	}
	double pRec(double x, int k, int ipn_n) {
		double result = 0;
		if (k < ipn_n) {
			result = diff.getNMA(0,k);
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

	void printDiff() { diff.printNMA(); }

	void setDiff() {
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				diff.setNMA(i,j,getDiffSum(i, j));
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

#endif NM_IPN_CLASS_H
