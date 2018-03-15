/*
	Author: reznikovkg
	GitHub: https://github.com/reznikovkg
	Email: kosrez1@yandex.ru

	Project name: Interpolation polinom by Newton
	File name: ipn_function.h
	GitHub Repository: https://github.com/reznikovkg/nm-ipN
*/

//class for common function for testing and comparison with polynom
class ipn_F
{
private:

	typedef double(*Func)(double);

	Func f;
	double a;
	double b;
	double h;
	int n;
	ipn_A points;

public:

	ipn_F(Func ff, double fa, double fb, double fh, double) {
		f = ff; a = fa; b = fb; h = fh;
		n = (int)((b - a) / h);
		points = ipn_A(2, n);	//decart system
		setPointsH();
	};
	ipn_F(Func ff, double fa, double fb, int fn) {
		f = ff; a = fa; b = fb; n = fn;
		h = (b - a) / (n - 1);
		points = ipn_A(2, n);	//decart system
		setPointsN();
	};

	double getF(double x) { return this->f(x); }
	double getA() { return this->a; }
	double getB() { return this->b; }
	double getH() { return this->h; }
	double getN() { return this->n; }
	ipn_A getPoints() { return this->points; }
	double getPoint(int fi, int fj) { return this->points.getIPNA(fi, fj); }

	void setPointsH() {
		for (int j = 1; j <= points.getAj(); j++) {
			points.setIPNA(1, j, a + h * (j - 1));
			points.setIPNA(2, j, f(a + h * (j - 1)));
		}
	}
	void setPointsN() {
		for (int j = 1; j <= points.getAj(); j++) {
			points.setIPNA(1, j, a + h * (j - 1));
			points.setIPNA(2, j, f(a + h * (j - 1)));
		}
	}
	
	void setPoints(int fi, int fj, double fk) {
		this->points.setIPNA(fi, fj, fk);
	}

	~ipn_F() {}
};
