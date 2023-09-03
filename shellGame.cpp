// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

// Additional includes, not used in this code, but may be needed in other contexts
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <cmath>

int main() {
    // Input and output file streams (commented out in this code)
    // ifstream fin("shell.in");
    // ofstream fout("shell.out");

    int N, numpoints, maxpoints;

    // Read the # of swaps from the input
    cin >> N;

    // Initialize vectors to store swap information and pebble positions
    vector<int> guesses(N);            // Stores Elsie's guesses
    vector<pair<int, int>> swaps(N);   // Stores the pairs of shells swapped
    vector<bool> isPebble(4, false);   // Represents the positions of the pebble (1-based)

    maxpoints = 0;  // Initialize the maximum points to 0

    // Read swap information and Elsie's guesses
    for (int u = 0; u < N; u++) {
        cin >> swaps[u].first >> swaps[u].second >> guesses[u];
    }

    // Loop through each starting position (1, 2, 3)
    for (int start = 1; start < 4; start++) {
        numpoints = 0;  // Initialize the number of correct guesses to 0

        // Reset the pebble positions to false for all shells
        for (int i = 0; i < 4; i++) {
            isPebble[i] = false;
        }

        // Set the pebble's initial position based on the starting shell
        isPebble[start] = true;

        // Simulate the swaps and Elsie's guesses
        for (int r = 0; r < N; r++) {
            // Swap the positions of two shells
            swap(isPebble[swaps[r].first], isPebble[swaps[r].second]);

            // Check if Elsie's guess matches the pebble's position
            if (isPebble[guesses[r]]) {
                numpoints++; // Increment the correct guess count
            }
        }

        // Update the maximum points by taking the maximum of the current count
        // and the previous maximum
        maxpoints = max(numpoints, maxpoints);
    }

    // Output the maximum points Elsie could have earned
    cout << maxpoints;
	
    return 0;
    //This code is not the simplest solution, but I demonstrate an accurate solution to this problem

}
