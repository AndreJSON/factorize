#include "pollard.hpp"
#include <iostream>
#define endl "\n"
using std::cout;

Pollard::Pollard() {};

void Pollard::factorize(const mpz_class& num) {
	interrupted = false;
	deadline = now() + std::chrono::milliseconds(maxMillis);
	res.clear();
	factors.push(num);
	gmp_randinit_mt(randomState);
	gmp_randseed_ui(randomState, time(0));
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

void Pollard::breakDown(mpz_class& num) {
	mpz_class x, gcd, tmp;
	mpz_urandomm(x.get_mpz_t(),randomState,num.get_mpz_t());
	mpz_class y = x;
	for(int lapsLeft = batchSize; lapsLeft > 0; lapsLeft--) {
		x = (x*x+1) % num;
		y = (y*y+1) % num;
		y = (y*y+1) % num;
		tmp = y-x;
		mpz_gcd(gcd.get_mpz_t(), tmp.get_mpz_t(), num.get_mpz_t());
		if(gcd != 1 && gcd != num) { //Non-trivial divisor found.
			factors.push(gcd);
			factors.push(num/gcd);
			return;
		}
	}
	if(now() > deadline) {
		interrupted = true;
		return;
	} else {
		factors.push(num);
	}
}

void Pollard::print() const {
	if(interrupted) {
		cout << "fail" << endl;
		return;
	}
	for(auto i : res) {
		cout << i.get_mpz_t() << endl;
	}
}