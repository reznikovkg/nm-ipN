/*
	Author: reznikovkg
	GitHub: https://github.com/reznikovkg
	Email: kosrez1@yandex.ru

	Project name: Interpolation polinom by Newton
	File name: ipn_polynom.h
	GitHub Repository: https://github.com/reznikovkg/nm-ipN
*/

// class interpolation polinom by Newton
class ipn_P
{
private:
	ipn_A points;
	int n;
	ipn_A diff;

public:
	ipn_P(ipn_A ppoints) {
		points = ppoints;
		n = points.getAj();
		diff = ipn_A(n, n);
		setDiff();
	}

	double p(double x) {
		return points.getIPNAa(1, 0) + pRec(x, 1, n);
	}
	double pRec(double x, int k, int ipn_n) {
		double result = 0;
		if (k < ipn_n) {
			result = diff.getIPNAa(0,k);
			result *= pRecProd(x, k);
			result += pRec(x, k + 1, ipn_n);
		}
		return result;
	}
	double pRecProd(double x, int k) {
		double result = 1;
		for (int i = 0; i < k; i++) {
			result *= (x - points.getIPNAa(0, i));
		}
		return result;
	}

	void printDiff() { diff.printIPNA(); }

	void setDiff() {
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				diff.setIPNAa(i,j,getDiffSum(i, j));
			}
		}
	}
	double getDiffSum(int i, int j) {
		double sum = 0;
		for (int sum_j = i; sum_j <= j; sum_j++) {
			sum += (points.getIPNAa(1,sum_j) / getDiffProd(sum_j, i, j));
		}
		return sum;
	}
	double getDiffProd(int sum_j, int i, int j) {
		double prod = 1;
		for (int prod_j = i; prod_j <= j; prod_j++) {
			if (prod_j != sum_j) {
				prod *= (points.getIPNAa(0, sum_j) - points.getIPNAa(0, prod_j));
			}
		}
		return prod;
	}

	~ipn_P() {}
};
