// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

const int max_position = 2000; // Define the maximum position as 2000.

int main() {
    ifstream fin("billboard.in"); // Input stream for reading.
    ofstream fout("billboard.out"); // Output stream for writing.

    int unmodx1, unmody1, unmodx2, unmody2; // Define variables to store billboard and truck coordinates.
    int x1, x2, y1, y2;

    vector<vector<bool>> isvisible(max_position, vector<bool>(max_position, false)); // Create a 2D boolean array.

    for (int i = 0; i < 2; i++) { // Loop twice to read coordinates for two billboards.
        cin >> unmodx1 >> unmody1 >> unmodx2 >> unmody2; // Read billboard coordinates.
        x1 = unmodx1 + 1000; // Shift x coordinates to be non-negative.
        x2 = unmodx2 + 1000;
        y1 = unmody1 + 1000; // Shift y coordinates to be non-negative.
        y2 = unmody2 + 1000;

        for (int u = x1; u < x2; u++) { // Mark the area of the billboard as visible.
            for (int n = y1; n < y2; n++) {
                isvisible[u][n] = true;
            }
        }
    }

    cin >> unmodx1 >> unmody1 >> unmodx2 >> unmody2; // Read truck coordinates.
    x1 = unmodx1 + 1000;
    x2 = unmodx2 + 1000;
    y1 = unmody1 + 1000;
    y2 = unmody2 + 1000;

    for (int t = x1; t < x2; t++) {
        for (int h = y1; h < y2; h++)
            if (isvisible[t][h]) {
                isvisible[t][h] = false; // Mark the area of the truck as not visible.
            }
    }

    int visible_squares = 0;

    for (int g = 0; g < max_position; g++) {
        for (int p = 0; p < max_position; p++)
            if (isvisible[g][p]) {
                visible_squares++; // Count the number of visible squares.
            }
    }

    cout << visible_squares; // Output the total number of visible squares.

    return 0; // End of the program.
}
