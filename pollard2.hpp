#include <gmp.h>
#include <gmpxx.h>
#include <list>
#include <vector>
#include <stack>
#include <utility>
#include <chrono>
using std::vector;
using std::stack;
using std::pair;

class Pollard2 {
private:
	vector<mpz_class> res;
	stack<mpz_class> factors;
	bool interrupted = false;
	int maxMillis = 400, batchSize = 100000, batchSizeNaive = 1000000;
	mpz_class iPrev = 2;
	std::chrono::duration<double,std::milli> deadline;
	std::chrono::duration<double,std::milli> now() {
    	return std::chrono::high_resolution_clock::now().time_since_epoch();
	}
	gmp_randstate_t randomState;
public:
	Pollard2();
	void factorize(const mpz_class& num);
	void breakDown(mpz_class& num);
	void breakDownNaive(mpz_class& num);
	void print() const;
};