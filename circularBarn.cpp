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
    ifstream fin("cbarn.in"); // Input stream from "cbarn.in" file.
    ofstream fout("cbarn.out"); // Output stream to "cbarn.out" file.

    int N, cows, index; // Declare variables for the number of rooms and cows, and index
    int maxcows = 0; // Initialize the maximum number of cows as 0.
    int minmove = 99999999; // Initialize the minimum move distance as a large number.
    int move = 0; // Initialize the current move distance as 0.
    int index; // Declare an index variable.

    fin >> N; // Read the number of rooms from the input.

    vector<int> roomsize(N); // Create a vector to store room sizes.

    for (int u = 0; u < N; u++) {
        fin >> roomsize[u]; // Read the number of cows in each room.
        maxcows += roomsize[u]; // Calculate the total number of cows.
    }

    for (int i = 0; i < N; i++) {
        cows = maxcows; // Set the current cows as the maximum cows.
        cows -= roomsize[i]; // Remove the cows in the starting room.

        for (int j = i + 1; j < i + N; j++) {
            move += cows; // Add the cows' movement to the total distance.
            index = j % N; // Wrap around to the beginning if needed.
            cows -= roomsize[index]; // Remove the cows in the next room.
        }

        minmove = min(move, minmove); // Keep track of the minimum total distance.

        move = 0; // Reset the distance for the next starting room.
    }

    fout << minmove; // Write the minimum total distance to the output file.

    return 0; // Exit the program.
}
