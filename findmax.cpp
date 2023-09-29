// findmax.cpp
// A function to find the max value in an array of integers. The given function
// assumes that there is at least one element in the given array.
#include <iostream>
using namespace std;

int findmax (int a[], size_t n);

int main () {
	// A small sample array for testing
	int array[] = { 7, 2, 18, 9, 1, 11, 17, 5 };
	size_t array_size = sizeof(array) / sizeof(int);

	// Print the max value in the array
	cout << findmax(array, array_size) << endl;
}

int findmax (int a[], size_t n) {
	// If only one element in the array, max value is first element
	if (n == 1)
		return a[0];
	// Find the max value in the sub-array beginning at element 1 through
	// the end of the array (passes a pointer to the second element as the
	// array parameter as the base of the smaller array being passed)
	int x = findmax(&a[1], n - 1);
	// Max value is the max of the value determined above (x) or the first
	// element of the array
	if (x > a[0])
		return x;
	return a[0];
}