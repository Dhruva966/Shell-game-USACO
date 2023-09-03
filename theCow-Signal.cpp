#include <bits/stdc++.h>
#include <string>
#include <cmath>
#include <vector>

using namespace std;

int main() {
    int m, n, k; // Declare integer variables for signal dimensions and amplification factor.

    cin >> m >> n >> k; // Read values of m, n, and k from input.

    vector<vector<char>> oldsignal(m, vector<char>(n)); // Create a 2D vector to store the original signal.

    for (int e = 0; e < m; e++) {
        for (int y = 0; y < n; y++) {
            cin >> oldsignal[e][y]; // Read the characters of the original signal.
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < k; j++) {
            for (int r = 0; r < n; r++) {
                for (int c = 0; c < k; c++) {
                    cout << oldsignal[i][r]; // Output characters of the enlarged signal in the row.
                }
            }
            cout << "\n"; // Move to the next line in the enlarged signal.
        }
    }

    return 0; // End of the program.
}
