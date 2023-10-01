#include <bits/stdc++.h>
using namespace std;

int main() {
    // Read input from file "cownomics.in" and write output to file "cownomics.out"
    ifstream fin("cownomics.in");
    ofstream fout("cownomics.out");

    int N, M;
    int tempcount = 0; // Temporary count for matching characters at a position
    int count1 = 0; // Count of positions that could potentially explain spottiness

    set<int> tempset; // Temporary set to store characters for spotty cows at a position
    set<int> tempset2; // Temporary set to store characters for plain cows at a position

    // Read the number of cows and length of the genome
    fin >> N >> M;

    // Initialize vectors to store the genomes of spotty and plain cows
    vector<string> spotty(M);
    vector<string> plain(M);
    vector<vector<int>> S(N, vector<int>(M)); // Vector to store spotty cow genomes
    vector<vector<int>> P(N, vector<int>(M)); // Vector to store plain cow genomes

    // Read the genomes of spotty cows
    for (int i = 0; i < N; i++) {
        fin >> spotty[i];

        // Convert characters to integers based on their DNA representation
        for (int u = 0; u < M; u++) {
            if (spotty[i][u] == 'A') {
                S[i][u] = 0;
            } else if (spotty[i][u] == 'C') {
                S[i][u] = 1;
            } else if (spotty[i][u] == 'T') {
                S[i][u] = 2;
            } else if (spotty[i][u] == 'G') {
                S[i][u] = 3;
            }
        }
    }

    // Read the genomes of plain cows
    for (int i = 0; i < N; i++) {
        fin >> plain[i];

        // Convert characters to integers based on their DNA representation
        for (int u = 0; u < M; u++) {
            if (plain[i][u] == 'A') {
                P[i][u] = 0;
            } else if (plain[i][u] == 'C') {
                P[i][u] = 1;
            } else if (plain[i][u] == 'T') {
                P[i][u] = 2;
            } else if (plain[i][u] == 'G') {
                P[i][u] = 3;
            }
        }
    }

    // Iterate over each position in the genome
    for (int k = 0; k < M; k++) {
        // Iterate over each spotty cow's genome at this position
        for (int y = 0; y < N; y++) {
            // Check if this character matches any character in the plain cows' genomes at this position
            for (int j = 0; j < N; j++) {
                if (S[y][k] == P[j][k]) {
                    tempcount++;
                } else {
                    continue;
                }
                break;
            }

            // If there's a match, no need to check further, break the loop
            if (tempcount != 0) {
                break;
            }
        }

        // If there was no match for any spotty cow, increment the count of potential explaining positions
        if (tempcount == 0) {
            count1++;
        }

        // Reset the temporary count for the next position
        tempcount = 0;
    }

    // Write the count of potential explaining positions to the output file
    fout << count1;

    return 0;
}
