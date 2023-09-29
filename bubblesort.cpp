// bubblesort.cpp
// Three versions of the bubble sort algorithm.
#include <iostream>
using namespace std;

void bubblesort1 (int a[], size_t n);
void bubblesort2 (int a[], size_t n);
void bubblesort3 (int a[], size_t n);

int main () {
	// A small sample array for testing
	int array[] = { 7, 2, 18, 9, 1, 11, 17, 5 };
	size_t array_size = sizeof(array) / sizeof(int);

	// Get bubble sort version to run
	char version;
	cout << "Enter bubble sort version: ";
	cin >> version;

	// Sort the array
	switch (version) {
		case '1': bubblesort1(array, array_size); break;
		case '2': bubblesort2(array, array_size); break;
		case '3': bubblesort3(array, array_size); break;
	}

	// Print the array
	for (int n : array)
		cout << ' ' << n;
	cout << endl;
}

// Version 1
// Performs N-1 passes over the array, where each pass makes a comparison
// of every pair of adjacent elements of the array. For each pair that are
// out of order, the values are swapped.
void bubblesort1(int a[], size_t n) {
	for (size_t i = 0; i < n - 1; i++)
		for (size_t j = 0; j < n - 1; j++)
			if (a[j + 1] < a[j]) {
				int tmp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = tmp;
			}
}

// Version 2
// A modification of version 1 such that each subsequent pass over the array
// compares one fewer pair of elements in the array. This version recognizes
// that with each pass, the greatest element considered moves into its
// correct position and need not be considered in future passes.
void bubblesort2(int a[], size_t n) {
	for (size_t i = 0; i < n - 1; i++)
		for (size_t j = 0; j < n - 1 - i; j++)
			if (a[j + 1] < a[j]) {
				int tmp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = tmp;
			}
}

// Version 3
// In this version, the number of passes over the array is not pre-determined.
// This version continues to perform passes over the entire array until a
// pass results in no swaps of elements.
void bubblesort3(int a[], size_t n) {
	size_t swap_count;
	do {
		swap_count = 0;
		for (size_t i = 0; i < n - 1; i++)
			if (a[i + 1] < a[i]) {
				int tmp = a[i];
				a[i] = a[i + 1];
				a[i + 1] = tmp;
				swap_count++;
			}
	} while (swap_count);
}