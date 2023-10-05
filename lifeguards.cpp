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

    // Read the input from lifeguards.in
    ifstream fin("lifeguards.in");
    // Write the output to lifeguards.out
    ofstream fout("lifeguards.out");

    int initial = 0; // Initialize the initial time
    int count = 0; // Initialize a count variable
    int countmax = -1; // Initialize the maximum count variable
    int N;

    fin >> N; // Read the number of lifeguards

    vector<pair<int, int>> times(N); // Create a vector to store lifeguard shifts
    vector<int> lifeguards(1000, 0); // Create a vector to track lifeguards' presence during the day

    for(int i = 0; i < N; i++){

        fin >> times[i].first >> times[i].second; // Read each lifeguard's shift start and end times

        // Update lifeguard presence during their shift
        for(int j = times[i].first; j < times[i].second; j++){
            lifeguards[j]++;
            initial = max(initial, j); // Update the latest time a lifeguard is present
        }

    }

    for(int p = 0; p < N; p++){

        // Update lifeguard presence during their shift
        for(int k = times[p].first; k < times[p].second; k++){
            lifeguards[k]--;
        }

        // Count the covered time
        for(int m = 0; m < initial + 1; m++){
            if(lifeguards[m] > 0){
                count++;
            }
        }

        countmax = max(countmax, count); // Update the maximum covered time
        count = 0; // Reset the count

        // Restore lifeguard presence during their shift
        for(int h = times[p].first; h < times[p].second; h++){
            lifeguards[h]++;
        }

    }

    fout << countmax; // Write the result to lifeguards.out

    return 0;
}
