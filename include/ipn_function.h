#ifndef IPN_FUNCTION_H

/*
	Author: reznikovkg
	GitHub: https://github.com/reznikovkg
	Email: kosrez1@yandex.ru

	Project name: Interpolation polinom by Newton
	File name: ipn_function.h
	GitHub Repository: https://github.com/reznikovkg/nm-ipN
*/

#define IPN_FUNCTION_H

//class for common function for testing and comparison with polynom
class ipn_Function
{
private:
	typedef double(*Func)(double);
	Func ipnF;
	double a; double b;
	int n; double h;
	ipn_Points points;

public:

	ipn_Function() {}
	
	ipn_Function(char typeParam,Func ff, double fa, double fb, double fparam) {
		ipnF = ff; a = fa; b = fb;
		switch (typeParam)
		{
		case 'h': {
			n = (int)((b - a) / fparam) + 1;
			points = ipn_Points(n);
			break;
		}
		case 'n': {
			h = (b - a) / (fparam - 1);
			points = ipn_Points(fparam);
			break;
		}
		default:
			break;
		}
		setPoints();
	};

	double f(double x) { return this->ipnF(x); }

	double getA() { return this->a; } void setA(double fa) { a = fa; }
	double getB() { return this->b; } void setB(double fb) { b = fb; }
	double getH() { return this->h; } void setH(double fh) { h = fh; }
	double getN() { return this->n; } void setN(int fn) { n = fn; }

	ipn_Points getPoints() { return this->points; }
	void setPoints() {
		for (int i = 1;i <= points.getN(); i++) {
			points.setX(i, a + h * (i - 1));
			points.setY(i, f(a + h * (i - 1)));
		}
	}
	void printPoints() { points.printIPNA(); }
	
	double getPointX(int i) { return this->points.getX(i); }
	double getPointY(int i) { return this->points.getY(i); }

	~ipn_Function() {}
};

#endif IPN_FUNCTION_H
