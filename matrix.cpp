// matrix1.cpp
// Creates a matrix (two-dimensional array, implemented with vectors) and
// populates the matrix as follows:
//	- The upper-left entry is set to 1
//	- All remaining entries are set to the sum of all values to the left and
//		all values above.
// After populating the matrix, the matrix is output to the console, but
// only if both dimentions are less than or equal to 8 (due to formatting).
#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

int main () {
	size_t rows, columns;

	// Get number of rows and columns, both must be non-zero
	cout << "Enter rows and columns: ";
	cin >> rows >> columns;
	if (!rows || !columns) {
		cerr << "Rows and columns must be positive.\n";
		exit(1);
	}

	// Create the matrix, two-dimensional vector
	vector<vector<int>> matrix;
	for (size_t i = 0; i < rows; i++)
		matrix.push_back(vector<int>(columns));

	// Set row 0 column 0 to 1
	matrix[0][0] = 1;

	// For all remaining entries, set to sum of all values in preceeding
	// row and column
	for (size_t i = 0; i < rows; i++) {
		for (size_t j = 0; j < columns; j++) {
			// Initialize sum, except for row 0 column 0
			if (i || j)
				matrix[i][j] = 0;
			// Add all previous values in row
			for (size_t k = 0; k < j; k++)
				matrix[i][j] += matrix[i][k];
			// Add all previous values in column
			for (size_t k = 0; k < i; k++)
				matrix[i][j] += matrix[k][j];
		}
	}

	// Output the matrix, but only if both dimensions <= 8
	if (rows <= 8 && columns <= 8)
		for (size_t i = 0; i < rows; i++) {
			for (size_t j = 0; j < columns; j++)
				cout << setw(8) << matrix[i][j];
			cout << endl;
		}
}