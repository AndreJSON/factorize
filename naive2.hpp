#include <gmp.h>
#include <gmpxx.h>
#include <list>
#include <vector>
#include <stack>
#include <utility>
using std::vector;
using std::stack;
using std::pair;

class Naive2 {
private:
	vector<mpz_class> res;
	stack<pair<mpz_class,mpz_class>> factors;
	bool interrupted = false;
public:
	Naive2();
	void factorize(const mpz_class& num);
	void breakDown(const pair<mpz_class,mpz_class>& num);
	void print() const;
};