#include "naive.hpp"
#include <iostream>
#define endl "\n"
using std::cout;

Naive::Naive() {};

void Naive::factorize(const mpz_class& num) {
	res.clear();
	factors.push(num);
	mpz_class top;
	while(!factors.empty()) {
		top = factors.top();
		factors.pop();
		if(mpz_probab_prime_p(top.get_mpz_t(),15) > 0) {
			res.push_back(top);
		} else {
			breakDown(top);
		}
	}
}

void Naive::breakDown(const mpz_class& num) {
	mpz_class root;
	mpz_sqrt(root.get_mpz_t(), num.get_mpz_t());
	mpz_class tmp;
	for(mpz_class i = 2; i <= root; i++) {
		if(num % i == 0) { //meaning num is divisible by i.
			factors.push(i);
			factors.push(num/i);
			return;
		}
	}
}

void Naive::print() const {
	if(interrupted) {
		cout << "fail" << endl;
		return;
	}
	for(auto i : res) {
		cout << i.get_mpz_t() << endl;
	}
}