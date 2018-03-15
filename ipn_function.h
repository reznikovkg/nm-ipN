
class ipn_F
{
private:
	typedef double(*Func)(double);

	Func f;
	double a;
	double b;
	double h;
	int n;
	ipn_A point;

public:
	ipn_F(Func ff, double fa, double fb, double fh, double) {
		f = ff; a = fa; b = fb; h = fh;
		n = (int)((b - a) / h);
		point = ipn_A(2, n);	//decart system
	};
	ipn_F(Func ff, double fa, double fb, int fn) {
		f = ff; a = fa; b = fb; n = fn;
		h = (b - a) / (n - 1);
		point = ipn_A(2, n);	//decart system
	};

	double getF(double x) { return this->f(x); }
	double getA() { return this->a; }
	double getB() { return this->b; }
	double getH() { return this->h; }
	double getN() { return this->n; }

	void setPointH() {
		for (int j = 1; j <= point.getAj(); j++) {
			point.setIPNA(1, j, a + h * (j - 1));
			point.setIPNA(2, j, f(a + h * (j - 1)));
		}
	}
	void setPointN() {
		for (int j = 1; j <= point.getAj(); j++) {
			point.setIPNA(1, j, a + h * (j - 1));
			point.setIPNA(2, j, f(a + h * (j - 1)));
		}
	}
	double getPoint(int fi, int fj) {
		return this->point.getIPNA(fi, fj);
	}
	void setPoint(int fi, int fj, double fk) {
		this->point.setIPNA(fi, fj, fk);
	}
	~ipn_F() {}
};
