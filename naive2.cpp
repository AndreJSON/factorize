#include "naive2.hpp"
#include <iostream>
#define endl "\n"
using std::cout;

Naive2::Naive2() {};

void Naive2::factorize(const mpz_class& num) {
	res.clear();
	factors.push(pair<mpz_class,mpz_class>(num,2));
	pair<mpz_class,mpz_class> top;
	while(!factors.empty()) {
		top = factors.top();
		factors.pop();
		if(mpz_probab_prime_p(top.first.get_mpz_t(),15) > 0) {
			res.push_back(top.first);
		} else {
			breakDown(top);
		}
	}
}

void Naive2::breakDown(const pair<mpz_class,mpz_class>& num) {
	mpz_class root;
	mpz_sqrt(root.get_mpz_t(), num.first.get_mpz_t());
	mpz_class tmp;
	for(mpz_class i = num.second; i <= root; i++) {
		if(num.first % i == 0) { //meaning num is divisible by i.
			res.push_back(i);
			factors.push(pair<mpz_class,mpz_class>(num.first/i,i));
			return;
		}
	}
}

void Naive2::print() const {
	if(interrupted) {
		cout << "fail" << endl;
		return;
	}
	for(auto i : res) {
		cout << i.get_mpz_t() << endl;
	}
}