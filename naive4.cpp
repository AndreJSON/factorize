#include "naive4.hpp"
#include <iostream>
#define endl "\n"
using std::cout;

Naive4::Naive4() {};

void Naive4::factorize(const mpz_class& num) {
	srand(time(0));
	interrupted = false;
	deadline = now() + std::chrono::milliseconds(maxMillis) - std::chrono::milliseconds(mpz_sizeinbase(num.get_mpz_t(),10) * (rand()%4));
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

void Naive4::breakDown(pair<mpz_class,mpz_class>& num) {
	mpz_class batchLimit = num.second + batchSize;
	mpz_class tmp;
	for(mpz_class i = num.second; i <= batchLimit; i++) {
		if(num.first % i == 0) { //meaning num is divisible by i.
			res.push_back(i);
			factors.push(pair<mpz_class,mpz_class>(num.first/i,i));
			return;
		}
	}
	//If we have tried enough factors, see if we have time for more.
	if(now() > deadline) {
		interrupted = true;
		return;
	} else {
		num.second += batchSize;
		factors.push(num);
	}
}

void Naive4::print() const {
	if(interrupted) {
		cout << "fail" << endl;
		return;
	}
	for(auto i : res) {
		cout << i.get_mpz_t() << endl;
	}
}