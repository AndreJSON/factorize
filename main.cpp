#include "naive4.hpp"
#include <iostream>
#include <vector>
#include <gmp.h>
#include <gmpxx.h>
#define endl "\n"
using std::cin; using std::cout;
using std::vector;

int main(void) {
	Naive4 pol;
	mpz_class num;
	while(cin >> num) {
		if(num == 1) {
			cout << 1 << endl << endl;
			continue;
		}
		pol.factorize(num);
		pol.print();
		cout << endl;
	}
	return 0;
}