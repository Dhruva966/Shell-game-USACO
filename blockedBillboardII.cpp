// Source: https://usaco.guide/general/io
//THE FOLLOWING CODE IS CLAPPED
#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream fin("billboard.in"); // Input stream for reading.
    ofstream fout("billboard.out"); // Output stream for writing.

    int x1, y1, x2, y2, x3, y3, x4, y4; // Define variables to store billboard coordinates.

    // Read coordinates of the two billboards and store them in variables.
    fin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;

    // Check if the cow feed billboard obscures any part of the lawnmower billboard.
    if ((y3 < y2 && y2 < y4 && x3 > x1 && x4 < x2) || (y3 < y1 && y1 < y4 && x3 > x1 && x4 < x2) || (y4 < y2 && y3 > y1) || (x1 < x3 && x2 > x4)) {
        fout << (x2 - x1) * (y2 - y1); // Output the area of the lawnmower billboard.
    } else if (x3 < x1 && x4 > x1 && y4 > y2 && y1 > y3) {
        fout << (x2 - x4) * (y2 - y1); // Output the area when part of the lawnmower billboard is obscured on the left.
    } else if (x3 < x2 && x4 > x2 && y4 > y2 && y1 > y3) {
        fout << (y2 - y1) * (x3 - x1); // Output the area when part of the lawnmower billboard is obscured on the right.
    } else if (x3 < x1 && x2 < x4 && y4 > y2 && y3 < y2) {
        fout << (y3 - y1) * (y2 - y1); // Output the area when part of the lawnmower billboard is obscured at the top.
    } else if (x3 < x1 && x4 > x2 && y4 > y1 && y1 > y3) {
        fout << (y2 - y4) * (x2 - x1); // Output the area when part of the lawnmower billboard is obscured at the bottom.
    } else if (x3 < x1 && x2 < x4 && y4 > y2 && y1 > y3) {
        fout << 0; // Output 0 if the lawnmower billboard is completely obscured.
    } else {
        fout << (x2 - x1) * (y2 - y1); // Output the area of the lawnmower billboard.
    }

    return 0; // End of the program.
}
