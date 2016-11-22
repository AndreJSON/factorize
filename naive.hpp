#include <gmp.h>
#include <gmpxx.h>
#include <list>
#include <vector>
#include <stack>
using std::vector;
using std::stack;

class Naive {
private:
	vector<mpz_class> res;
	stack<mpz_class> factors;
public:
	Naive();
	void factorize(const mpz_class& num);
	void breakDown(const mpz_class& num);
	void print() const;
};