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
    ifstream fin("speeding.in");
    ofstream fout("speeding.out");

    // Declare variables
    int N, M;
    int maxin = 0; // Variable to store the maximum over-speeding value
    int o = 0;    // Offset variable for segment limits
    int r = 0;    // Offset variable for journey speeds

    // Vector to store speed limits for each segment
    vector<int> limits(1000);

    // Input the number of speed limit segments and the number of segments covered in the journey
    fin >> N >> M;

    // Vectors to store speed limit segments and journey segments
    vector<pair<int, int>> journey(1000);
    vector<pair<int, int>> segment(1000);

    // Input the speed limit segments
    for (int i = 0; i < N; i++) {
        fin >> segment[i].first >> segment[i].second;
    }

    // Input the journey segments
    for (int u = 0; u < M; u++) {
        fin >> journey[u].first >> journey[u].second;
    }

    // Fill the limits vector with speed limits for each unit distance in the segment
    for (int m = 0; m < N; m++) {
        for (int y = 0; y < segment[m].first; y++) {
            limits[y + o] = segment[m].second;
        }
        o += segment[m].first;
    }

    // Check for over-speeding in each unit distance of the journey
    for (int p = 0; p < M; p++) {
        for (int z = 0; z < journey[p].first; z++) {
            // Compare journey speed with speed limit and update the maximum over-speeding value
            if (limits[z + r] < journey[p].second) {
                maxin = max((journey[p].second - limits[z + r]), maxin);
            }
        }
        r += journey[p].first;
    }

    // Output the maximum over-speeding value
    fout << maxin;

    // Indicate successful program execution
    return 0;
}
