// Source: https://usaco.guide/general/io

#include <iostream> // Include the input/output stream library.
#include <fstream> // Include the file stream library for file input/output operations.
#include <cmath> // Include the math library for mathematical operations.
#include <algorithm> // Include the algorithm library for sorting.
#include <vector> // Include the vector library for managing dynamic arrays.

using namespace std;

int main() {
    int d, e, f, g, h, i, j; // Declare integer variables.

    cin >> d >> e >> f >> g >> h >> i >> j; // Read seven integers from input.

    vector<int> abc = {d, e, f, g, h, i, j}; // Create a vector containing the seven integers.

    sort(abc.begin(), abc.end()); // Sort the vector in ascending order.

    int A = abc[0]; // A is the smallest element in the sorted vector.
    int B = abc[1]; // B is the second smallest element in the sorted vector.
    int C = abc[6] - A - B; // C is calculated as the difference between the largest element and A and B.

    cout << A << " " << B << " " << C; // Output A, B, and C separated by spaces.

    return 0; // End of the program.
}
