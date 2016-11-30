#include "pollard2.hpp"
#include <iostream>
#define endl "\n"
using std::cout;

Pollard2::Pollard2() {};

void Pollard2::factorize(const mpz_class& num) {
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
			if(top > 99999) {
				breakDown(top);
			} else {
				breakDownNaive(top);
			}
		}
	}
}

void Pollard2::breakDown(mpz_class& num) {
	mpz_class x, gcd, tmp;
	mpz_urandomm(x.get_mpz_t(),randomState,num.get_mpz_t());
	mpz_class y = x;
	for(int lapsLeft = batchSize; lapsLeft > 0; lapsLeft--) {
		//Generate new values of x and y.
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

void Pollard2::breakDownNaive(mpz_class& num) {
	mpz_class batchLimit = iPrev + batchSizeNaive;
	mpz_class tmp;
	for(mpz_class i = iPrev; i <= batchLimit; i++) {
		if(num % i == 0) { //meaning num is divisible by i.
			res.push_back(i);
			factors.push(num/i);
			iPrev = 2;
			return;
		}
	}
	//If we have tried enough factors, see if we have time for more.
	if(now() > deadline) {
		interrupted = true;
		iPrev = 2;
		return;
	} else {
		iPrev+= batchSizeNaive;
		factors.push(num);
	}
}

void Pollard2::print() const {
	if(interrupted) {
		cout << "fail" << endl;
		return;
	}
	for(auto i : res) {
		cout << i.get_mpz_t() << endl;
	}
}