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
    // ifstream fin("cbarn.in");
    // ofstream fout("cbarn.out");

    int N, cows;
    int maxcows = 0;
    int minmove = 99999999;
    int move = 0;
    int index;

    cin >> N; // Read the number of rooms.

    vector<int> roomsize(N);

    for (int u = 0; u < N; u++) {
        cin >> roomsize[u]; // Read the number of cows in each room.
        maxcows += roomsize[u]; // Calculate the total number of cows.
    }

    for (int i = 0; i < N; i++) {
        cows = maxcows;
        cows -= roomsize[i]; // Start with one room as the entrance and remove its cows.

        for (int j = i; j < i + N; j++) {
            if (i != j) {
                move += cows; // Add the cows' movement to the total distance.
                index = j % N; // Wrap around to the beginning if needed.
                cows -= roomsize[index]; // Remove the cows in the next room.
            } else {
                continue; // Skip the current room (already counted).
            }
        }

        if (i == N - 1) {
            move -= roomsize[0]; // Subtract the cows in the first room if the entrance is the last room.
        } else {
            move -= roomsize[i + 1]; // Subtract the cows in the next room if not the last.
        }

        minmove = min(move, minmove); // Keep track of the minimum total distance.

        move = 0; // Reset the distance for the next starting room.
    }

    cout << minmove; // Output the minimum total distance.

    return 0;
}
