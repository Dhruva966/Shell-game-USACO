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
    ifstream fin("buckets.in");
    ofstream fout("buckets.out");

    int bx = 0; // Initialize barn's x-coordinate.
    int by = 0; // Initialize barn's y-coordinate.
    int lx = 0; // Initialize lake's x-coordinate.
    int ly = 0; // Initialize lake's y-coordinate.
    int rx = 0; // Initialize rock's x-coordinate.
    int ry = 0; // Initialize rock's y-coordinate.

    for (int row = 0; row < 10; row++) {
        string row1;
        cin >> row1;

        for (int column = 0; column < 10; column++) {
            if (row1[column] == 'B') {
                bx = row;
                by = column;
            } else if (row1[column] == 'R') {
                rx = row;
                ry = column;
            } else if (row1[column] == 'L') {
                lx = row;
                ly = column;
            }
        }
    }

    int minimum_cows;

    // Check if the barn, rock, and lake are in a straight line horizontally.
    if (((bx == rx) && (bx == lx)) && (((by < ry) && (ry < ly)) || ((by > ry) && (ry > ly)))) {
        minimum_cows = max(abs(ly - by), abs(lx - bx)); // Calculate the distance between barn and lake.
        minimum_cows = minimum_cows + 2; // Add 2 for cows at barn and lake positions.
    } else {
        minimum_cows = abs(bx - lx) + abs(ly - by) - 1; // Calculate Manhattan distance between barn and lake.
    }

    cout << minimum_cows; // Output the minimum number of cows needed.

    // End of the program.
    return 0;
}
