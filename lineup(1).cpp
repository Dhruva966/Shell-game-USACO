// Source: https://usaco.guide/general/io
#include <bits/stdc++.h>
using namespace std;
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <fstream>

int main() {
    // Open input and output files
    ifstream fin("lineup.in");
    ofstream fout("lineup.out");

    // Declare variables
    int N;
    int r = 0;
    string g, h;

    // Input the number of constraints
    fin >> N;

    // Declare vectors to store cow names and constraints
    vector<string> cows(8);
    vector<pair<string, string>> values(100);

    // Define the names of the initial cows
    cows[0] = "Beatrice";
    cows[1] = "Belinda";
    cows[2] = "Bella";
    cows[3] = "Bessie";
    cows[4] = "Betsy";
    cows[5] = "Blue";
    cows[6] = "Buttercup";
    cows[7] = "Sue";

    // Sort the cow names alphabetically
    sort(cows.begin(), cows.end());

    // Input constraints and store them in the values vector
    for (int u = 0; u < N; u++) {
        fin >> g;

        for (int i = 0; i < 4; i++) {
            string temp;
            fin >> temp;
        }

        fin >> h;
        values[u] = make_pair(g, h);
    }

    // Find the alphabetically first ordering of cows that satisfies constraints
    while (next_permutation(cows.begin(), cows.end())) {
        for (int i = 0; i < N; i++) {
            auto a = find(cows.begin(), cows.end(), values[i].first);
            auto b = find(cows.begin(), cows.end(), values[i].second);

            // Check if the current ordering satisfies constraints
            if (abs(a - b) != 1) {
                r++;
            }
        }

        // If constraints are not satisfied, reset and continue with the next permutation
        if (r != 0) {
            r = 0;
            continue;
        } else {
            // If constraints are satisfied, break out of the loop
            break;
        }
    }

    // Output the final ordering of cows to the output file
    for (auto cow : cows) {
        fout << cow << "\n";
    }

    // Indicate successful program execution
    return 0;
}
