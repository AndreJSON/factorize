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

class Naive4 {
private:
	vector<mpz_class> res;
	stack<pair<mpz_class,mpz_class>> factors;
	bool interrupted = false;
	int maxMillis = 150, batchSize = 1000000;
	std::chrono::duration<double,std::milli> deadline;
	std::chrono::duration<double,std::milli> now() {
    	return std::chrono::high_resolution_clock::now().time_since_epoch();
	}
public:
	Naive4();
	void factorize(const mpz_class& num);
	void breakDown(pair<mpz_class,mpz_class>& num);
	void print() const;
};