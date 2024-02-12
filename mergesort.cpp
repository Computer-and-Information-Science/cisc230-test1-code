// mergesort.cpp
// A non-recursive version of the merge sort algorithm. The included merge
// function uses pointer arithmetic to accomplish the merge. Any test
// question will not ask about details of the merge code, but note that any
// call to the merge function has linear time complexity.
#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

void mergesort (int a[], size_t n);

int main () {
	// Initialize the RNG
	srand(time(0));

	// A dynamically created array for testing.
	size_t array_size;
	cout << "Enter array size: ";
	cin >> array_size;
	int *array = new int[array_size];

	// Fill array with random values.
	for (size_t i = 0; i < array_size; i++)
		array[i] = rand() % 90000 + 10000;

	// Print array if size <= 40.
	if (array_size <= 40)
		for (size_t i = 0; i < array_size; i++)
			cout << ' ' << array[i];
	cout << endl;

	// Sort the array
	mergesort(array, array_size);

	// Print array if size <= 40.
	if (array_size <= 40)
		for (size_t i = 0; i < array_size; i++)
			cout << ' ' << array[i];
	cout << endl;

	// Done
	cout << "Done." << endl;
}

// merge - Merge two adjacent sorted segments of an array.
//	Parameters:
//		a - an array of int
//		p1 - pointer to first element of first sorted segment
//		p2 - pointer to first element of second sorted segment
//		p3 - pointer past last element of second sorted segment
//		tmp - Temporary array, for merging
void merge (int* p1, int* p2, int* p3, int tmp[]) {

	int* a = p1; // points to an element in first segment
	int* b = p2; // points to an element in second segment
	int* c = tmp; // points to an element in the temporary array

	while (a < p2 && b < p3)
		*c++ = *a < *b ? *a++ : *b++;
	while (a < p2)
		*c++ = *a++;
	while (b < p3)
		*c++ = *b++;

	for (a = p1, c = tmp; a < p3; a++, c++)
		*a = *c;
}

// sort - Merge sort
//	Parameters:
//		a - an array of int
//		n - size of array a
void mergesort (int a[], size_t n) {
	int* tmp = new int[n];
	for (size_t size = 1; size < n; size *= 2) {
		for (size_t i = 0; i < n; i += 2 * size)
			merge(&a[i], std::min(&a[i + size], &a[n]),
				std::min(&a[i + 2 * size], &a[n]), tmp);
	}
	delete [] tmp;
}
