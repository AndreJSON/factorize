#include "naive.hpp"
#include <stdio.h>
#include <iostream>
#include <vector>
#include <gmp.h>
#include <gmpxx.h>
using std::cout; using std::endl; using std::cin;
using std::vector;

int main(void) {
	Naive s1;
	mpz_class num;
	cin >> num;
	cout << num << endl;
	return 0;
}