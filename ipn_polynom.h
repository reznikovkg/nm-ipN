// class interpolation polinom by Newton
class ipn_P
{
private:
	ipn_A point;
	int n;
	ipn_A diff;

public:
	ipn_P(ipn_A ppoints, int pn) {
		point = ppoints;


	}

	/*void ipn_set_table_x_fx() {
	ipn_table_x[0] = ipn_a; ipn_table_fx[0] = ipn_func(ipn_table_x[0]);
	ipn_table_x[ipn_n - 1] = ipn_b; ipn_table_fx[ipn_n - 1] = ipn_func(ipn_table_x[ipn_n - 1]);

	for (int i = 1; i < ipn_n - 1; i++) {
	ipn_table_x[i] = ipn_table_x[0] + i * ipn_h;
	ipn_table_fx[i] = ipn_func(ipn_table_x[i]);
	}
	}*/

	~ipn_P() {}
};
