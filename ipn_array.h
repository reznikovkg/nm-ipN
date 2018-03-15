//class array for points on decard system [or other, not problem]
class ipn_A
{
private:
	double** ipnA;
	int ipnAi;
	int ipnAj;

public:
	ipn_A() {}

	ipn_A(int ai, int aj) {
		ipnAi = ai; ipnAj = aj;

		ipnA = new double*[ipnAi];
		for (int i = 0; i < ipnAi; i++) {
			ipnA[i] = new double[ipnAj];
		}
	}

	double getIPNA(int ai, int aj) {
		return this->ipnA[ai - 1][aj - 1];
	}

	int getAi() { return this->ipnAj; }
	int getAj() { return this->ipnAj; }

	void setIPNA(int ai, int aj, double ak) {
		ipnA[ai - 1][aj - 1] = ak;
	}

	void printIPNA() {
		for (int i = 0; i < ipnAi; i++) {
			for (int j = 0; j < ipnAj; j++) {
				std::cout << "[" << i << "][" << j << "] = " << ipnA[i][j] << "    ";
			}
			std::cout << '\n';
		}
	}
	~ipn_A() {}
};