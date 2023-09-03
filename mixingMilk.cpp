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
    // Input streams for reading and output streams for writing are commented out.
    // ifstream fin("mixmilk.in");
    // ofstream fout("mixmilk.out");

    // Create a vector of pairs to represent the three buckets of milk.
    vector<pair<long long, long long>> milks(3);

    // Read the initial milk capacity and amount of milk in each bucket.
    for (int i = 0; i < 3; i++) {
        long long a, b;
        cin >> a >> b;
        milks[i] = make_pair(a, b);
    }

    // Perform 100 pour operations.
    for (int e = 0; e < 2; e++) {
        for (int u = 0; u < 3; u++) {
            if (u == 2) {
                // Pour from the third bucket to the first bucket.
                milks[0].second += milks[2].second;
                milks[2].second = 0;

                // Check if the first bucket has overflowed.
                if (milks[0].second > milks[0].first) {
                    milks[2].second += (milks[0].second - milks[0].first);
                    milks[0].second = milks[0].first;
                }
            } else {
                // Pour from one bucket to the next.
                milks[u + 1].second += milks[u].second;
                milks[u].second = 0;

                // Check if the next bucket has overflowed.
                if (milks[u + 1].second > milks[u + 1].first) {
                    milks[u].second += (milks[u + 1].second - milks[u + 1].first);
                    milks[u + 1].second = milks[u + 1].first;
                }
            }
        }
    }

    // Pour the remaining milk from bucket 1 to bucket 2.
    milks[1].second += milks[0].second;
    milks[0].second = 0;

    // Check if bucket 2 has overflowed.
    if (milks[1].second > milks[1].first) {
        milks[0].second += (milks[1].second - milks[1].first);
        milks[1].second = milks[1].first;
    }

    // Output the final amount of milk in each bucket.
    cout << milks[0].second << "\n" << milks[1].second << "\n" << milks[2].second;

    // Close the input and output streams if they were opened.
    // fin.close();
    // fout.close();

    // End of the program.
    return 0;
}
