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

class Pollard {
private:
	vector<mpz_class> res;
	stack<mpz_class> factors;
	bool interrupted = false;
	int maxMillis = 100, batchSize = 100000;
	std::chrono::duration<double,std::milli> deadline;
	std::chrono::duration<double,std::milli> now() {
    	return std::chrono::high_resolution_clock::now().time_since_epoch();
	}
	gmp_randstate_t randomState;
public:
	Pollard();
	void factorize(const mpz_class& num);
	void breakDown(mpz_class& num);
	void print() const;
};