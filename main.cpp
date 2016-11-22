#include "naive.hpp"
#include <iostream>
#include <vector>
#include <gmp.h>
#include <gmpxx.h>
using std::cin;
using std::vector;

int main(void) {
	Naive s1;
	mpz_class num;
	cin >> num;
	s1.factorize(num);
	s1.print();
	return 0;
}