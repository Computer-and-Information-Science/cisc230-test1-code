// sumarray.cpp
// Two recursive functions for computing the sum of an array of integers
#include <iostream>
using namespace std;

int sum1 (const int a[], size_t n);
int sum2 (const int a[], size_t n);

int main () {
	int array[] = { 7, 2, 18, 9, 1, 11, 17, 5 }; // sum is 70
	size_t array_size = sizeof(array) / sizeof(int);

	cout << sum1(array, array_size) << ' ' << sum2(array, array_size) << endl;
}

int sum1 (const int a[], size_t n) {
	// Finds the sum of an array recursively by adding the sum of all but
	// the last element to the last element. Base case is when the size is
	// given as zero.
	if (n)
		return sum1(a, n - 1) + a[n - 1];
	return 0;
}

int sum2 (const int a[], size_t n) {
	// Finds the sum of an array by a rather convoluted method. When the
	// size of the array is 2 or more, divide the array in half, find the
	// sum of the halves. When the size of the array is 1 (base case), the
	// sum is a[0]. When the size of the array is 0 (another base case), the
	// sum is 0.
	if (n > 1) {
		// Find the index of the middle
		size_t mid = n / 2;
		// Add the sum of the first half and the sum of the second half. The
		// start of the second half is computed using pointer arithmetic, e.g.
		// if mid is 4 then a+mid is a pointer to a[4].
		return sum2(a, mid) + sum2(a + mid, n - mid);
	}
	// Base case, return a[0]
	if (n == 1)
		return a[0];
	// Base case, return 0
	return 0;
}