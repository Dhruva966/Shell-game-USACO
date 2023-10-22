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
    // Define file streams for input and output.
    ifstream fin("badmilk.in");
    ofstream fout("badmilk.out");
	
    // Declare and initialize variables to store input.
    int N, M, S, D;
    int max_dose = 0;
    int dose = 0;

    // Read N, M, D, and S from input.
    fin >> N >> M >> D >> S;

    // Define data structures to store the milk-drinking and sickness data.
    vector<pair<int, pair<int, int>>> vec(D); // For milk-drinking data.
    vector<pair<int, int>> sick(S); // For sickness data.
    vector<int> repeats; // To keep track of people who drank bad milk multiple times.

    // Read milk-drinking data.
    for (int i = 0; i < D; i++) {
        fin >> vec[i].first >> vec[i].second.first >> vec[i].second.second;
    }

    // Read sickness data.
    for (int j = 0; j < S; j++) {
        fin >> sick[j].first >> sick[j].second;
    }

    // Iterate through the possibilities to find the minimum doses needed.
    for (int b = 0; b < M; b++) {
        for (int k = 0; k < S; k++) {
            for (int q = 0; q < D; q++) {
                if (sick[k].first == vec[q].first) {
                    if (vec[q].second.first == b) {
                        if (sick[k].second < vec[q].second.second) {
                            continue;
                        } else {
                            for (int g = 0; g < D; g++) {
                                auto it = find(repeats.begin(), repeats.end(), vec[g].first);
                                if (vec[g].second.first == b && it == repeats.end()) {
                                    repeats.push_back(vec[g].first);
                                    dose++;
                                }
                            }
                            max_dose = max(max_dose, dose);
                            dose = 0;
                            repeats.clear();
                        }
                    }
                }
            }
        }
    }

    // Output the minimum number of doses needed.
    fout << max_dose;
}
