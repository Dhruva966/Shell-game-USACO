// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <cmath>

int main() {
    // Input stream for reading and output stream for writing are created.
    ifstream fin("square.in");
    ofstream fout("square.out");

    int a, b, c, d, e, f, g, h; // Declare integers to represent coordinates of two rectangles.

    fin >> a >> b >> c >> d >> e >> f >> g >> h; // Read coordinates from the input.

    vector<int> x = {a, c, e, g}; // Store x-coordinates of all corners in a vector.
    vector<int> y = {b, d, f, h}; // Store y-coordinates of all corners in a vector.

    int minimum_area; // Declare a variable to store the minimum area of the square.

    sort(x.begin(), x.end()); // Sort the x-coordinates in ascending order.
    sort(y.begin(), y.end()); // Sort the y-coordinates in ascending order.

    int u = y[3] - y[0]; // Calculate the difference in y-coordinates.
    int v = x[3] - x[0]; // Calculate the difference in x-coordinates.

    if (u > v) { // If the y-coordinate difference is greater than the x-coordinate difference.
        minimum_area = u * u; // Calculate the square of the y-coordinate difference.
    } else {
        minimum_area = v * v; // Calculate the square of the x-coordinate difference.
    }

    fout << minimum_area; // Write the minimum area to the output file.

    // End of the program.
    return 0;
}
