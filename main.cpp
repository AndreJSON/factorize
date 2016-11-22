#include "naive.hpp"
#include <iostream>
#include <vector>
#include <gmp.h>
#include <gmpxx.h>
#define endl "\n"
using std::cin; using std::cout;
using std::vector;

int main(void) {
	Naive s1;
	mpz_class num;
	while(cin >> num) {
		if(num == 1) {
			cout << 1 << endl << endl;
			continue;
		}
		s1.factorize(num);
		s1.print();
		cout << endl;
	}
	return 0;
}