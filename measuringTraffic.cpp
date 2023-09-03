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
    // You can uncomment these to read from a file and write to an output file.
    // ifstream fin("traffic.in");
    // ofstream fout("traffic.out");

    int N, c, d, a, b; // Declare integer variables for N, c, d, a, and b.

    pair<int, int> interval; // Declare a pair of integers for interval.
    pair<int, int> interval2; // Declare another pair of integers for interval2.

    a = -1; // Initialize 'a' with -1.
    b = 1001; // Initialize 'b' with 1001.
    c = -1; // Initialize 'c' with -1.
    d = 1001; // Initialize 'd' with 1001.

    cin >> N; // Read the value of N from input.

    vector<pair<string, pair<int, int>>> traffics(N); // Create a vector of pairs to store traffic data.

    for (int i = 0; i < N; i++) { // Loop to read traffic data N times.
        cin >> traffics[i].first >> traffics[i].second.first >> traffics[i].second.second;
        // Read traffic information (string and two integers) and store it in the vector.

        if (traffics[i].first == "none") { // Check if the traffic type is "none".
            if (i > 0 && traffics[i - 1].first == "none") {
                // If there was a "none" before this, update 'a' and 'b'.
                a = max(a, traffics[i].second.first);
                b = min(b, traffics[i].second.second);
            } else {
                // Otherwise, set 'a' and 'b' to the current values.
                a = traffics[i].second.first;
                b = traffics[i].second.second;
            }
        } else if (traffics[i].first == "off") { // Check if the traffic type is "off".
            // Update 'a' and 'b' based on off-ramp traffic.
            a -= traffics[i].second.second;
            b -= traffics[i].second.first;
            a = max(0, a); // Ensure 'a' is not negative.
        } else { // Handle other traffic types.
            // Update 'a' and 'b' based on traffic flow.
            a += traffics[i].second.first;
            b += traffics[i].second.second;
        }
    }

    interval = make_pair(a, b); // Create the interval pair based on 'a' and 'b'.

    for (int i = N - 1; i >= 0; i--) { // Loop in reverse to process the second interval.
        if (traffics[i].first == "none") {
            if (i < N - 1 && traffics[i + 1].first == "none") {
                // Update 'c' and 'd' if there was a "none" before this.
                c = max(c, traffics[i].second.first);
                d = min(d, traffics[i].second.second);
            } else {
                // Otherwise, set 'c' and 'd' to the current values.
                c = traffics[i].second.first;
                d = traffics[i].second.second;
            }
        } else if (traffics[i].first == "off") {
            // Update 'c' and 'd' based on off-ramp traffic.
            c += traffics[i].second.first;
            d += traffics[i].second.second;
        } else {
            // Update 'c' and 'd' based on traffic flow.
            c -= traffics[i].second.second;
            d -= traffics[i].second.first;
            c = max(0, c); // Ensure 'c' is not negative.
        }
    }

    interval2 = make_pair(c, d); // Create the second interval pair.

    // Output the two intervals.
    cout << interval2.first << " " << interval2.second;
    cout << "\n" << interval.first << " " << interval.second;

    // End of the program.
    return 0;
}
