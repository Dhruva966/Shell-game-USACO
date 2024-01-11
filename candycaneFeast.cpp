// Source: https://usaco.guide/general/io
#include <iostream>
#include <vector>

using namespace std;

int main() {
    // Declare variables for the number of cows and candy canes
    long long N;
    long long M;

    // Input the number of cows and candy canes
    cin >> N >> M;

    // Initialize vectors to store the heights of cows and the characteristics of candy canes
    vector<long long> cows(N);
    vector<pair<long long, long long>> canes(M);

    // Input the initial heights of cows
    for (long long y = 0; y < N; y++) {
        cin >> cows[y];
    }

    // Input the heights of candy canes
    for (long long t = 0; t < M; t++) {
        cin >> canes[t].second;
        canes[t].first = 0;
    }

    // Iterate through each candy cane
    for (long long j = 0; j < M; j++) {
        // Iterate through each cow
        for (long long b = 0; b < N; b++) {
            // Check if the cow can eat the candy cane
            if ((cows[b] > canes[j].first) && canes[j].second >= cows[b]) {
                // Calculate the amount eaten by the cow and update heights
                long long f = (cows[b] - canes[j].first);
                canes[j].first += (cows[b] - canes[j].first);
                cows[b] += f;

                // Check if the candy cane is fully consumed
                if (canes[j].first >= canes[j].second) {
                    break;
                }
            }
            // Check if the cow can partially eat the candy cane
            else if ((cows[b] > canes[j].first) && canes[j].second < cows[b]) {
                // Update heights and set remaining candy cane height to 0
                cows[b] += (canes[j].second - canes[j].first);
                canes[j].second = 0;

                // Check if the candy cane is fully consumed
                if (canes[j].second == 0) {
                    break;
                }
            }
        }
    }

    // Output the final heights of each cow
    for (long long g = 0; g < N; g++) {
        cout << cows[g] << "\n";
    }

    // Indicate successful program execution
    return 0;
}
