#include <iostream>
#include "toy.h"

using namespace std;

int main() {
	seneca::Toy t1{ "  1000121         :              Red Bike           :  1  :  89.99  " };
	cout << t1 << endl;

	return 0;
}