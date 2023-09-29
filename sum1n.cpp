// sum1n.cpp
// Three function to compute the sum of the integers 1 through N.
#include <iostream>
using namespace std;

int sum1 (int n);
int sum2 (int n);
int sum3 (int n);

int main () {
	int n;
	cout << "Enter n: ";
	cin >> n;
	cout << sum1(n) << ' ' << sum2(n) << ' ' << sum3(n) << endl;
}

int sum1 (int n) {
	// Calculate using a while loop
	int i = 0;
	int sum = 0;
	while (i < n)
		sum += ++i;
	return sum;
}

int sum2 (int n) {
	// Recursive, find sum of 1 through n-1, then add n
	if (n > 0)
		return n + sum2(n - 1);
	// Base case, return 0
	return 0;
}

int sum3 (int n) {
	// Use the formula
	return n > 0 ? n * (n + 1) / 2 : 0;
}