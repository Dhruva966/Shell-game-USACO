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
    // Declare variables to store input values
    std::string number;
    long N, nights;

    // Initialize the minimum depth to a large value
    long minimumdepth = LONG_MAX;

    // Input the number of cows
    cin >> N;

    // Ignore the newline character
    cin.ignore();

    // Input the bitstring representing the state of the cows
    getline(std::cin, number);

    // Initialize vectors to store the state of cows and the count of infected cows
    vector<long> cows;
    vector<long> sick(N, 0);

    // Initialize a counter for infected cows
    long j = 1;

    // Process the bitstring to extract information about infected cows
    for (char c : number) {
        if (isdigit(c)) {
            int digit = c - '0';
            cows.push_back(digit);
        }
    }

    // Count the infected cows
    for (int h = 0; h < cows.size(); h++) {
        if (cows[h] == 1) {
            sick[j]++;
        } else {
            j++;
        }
    }

    // Calculate the minimum number of nights required to reach the current state
    for (long k = 1; k <= j; k++) {
        if (sick[k] != 0) {
            if (sick[k] % 2 == 0) {
                nights = sick[k] / 2;
            } else {
                nights = (sick[k] + 1) / 2;
            }
            // Update the minimum depth
            minimumdepth = min(nights, minimumdepth);
        }
    }

    // Special case handling for the situation where the first or last cow is infected
    if ((cows[0] == 1 && cows[1] == 0) || (cows[cows.size() - 1] == 1 && cows[cows.size() - 2] == 0)) {
        minimumdepth = 1;
    }

    // Initialize a counter for the total number of cows infected
    int r = 0;

    // Count the total number of cows infected
    for (int s = 1; s <= j; s++) {
        if (sick[s] != 0) {
            r += (sick[s] - (2 * minimumdepth - 2));
        }
    }

    // Output the result
    cout << r;

    // Indicate successful program execution
    return 0;
}
