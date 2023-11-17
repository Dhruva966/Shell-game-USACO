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

  // Input stream from the file "guess.in"
  ifstream fin("guess.in");
  // Output stream to the file "guess.out"
  ofstream fout("guess.out");

  // Number of animals
  int N;
  // Variables to track maximum "yes" answers
  int t = 0;
  int x = 0;
  int m = 0;
  int y = 0;

  // Read the number of animals from the input file
  fin >> N;

  // Vector to store characteristics of each animal
  vector<vector<string>> characteristics(N, vector<string>(1));
  // Vector to store names of each animal
  vector<string> name(N);

  // Loop through each animal
  for (int i = 0; i < N; i++) {
    // Number of characteristics for the current animal
    int p;
    // Read the name and number of characteristics for the current animal
    fin >> name[i] >> p;
    // Resize the vector to accommodate 'p' elements
    characteristics[i].resize(p);

    // Loop through each characteristic for the current animal
    for (int j = 0; j < p; j++) {
      // Read the characteristic and store it in the vector
      fin >> characteristics[i][j];
    }
  }

  // Nested loops to compare characteristics of different animals
  for (int z = 0; z < N - 1; z++) {
    for (int v = z + 1; v < N; v++) {
      // Reset counters
      x = 0;
      y = m = 0;

      // Loop through the characteristics of the first animal
      for (const auto& it : characteristics[z]) {
        // Loop through the characteristics of the second animal
        for (const auto& u : characteristics[v]) {
          // Check if there is a common characteristic
          if (characteristics[z][y] == characteristics[v][m]) {
            // Increment the counter for common characteristics
            x++;
            break;  // Break the inner loop if a match is found
          }
          // Move to the next characteristic of the second animal
          m++;
        }

        // Reset the inner index
        m = 0;
        // Move to the next characteristic of the first animal
        y++;
      }

      // Reset the outer index
      y = 0;
      // Update the maximum number of "yes" answers
      t = max(t, x);
    }
  }

  // Output the maximum number of "yes" answers to the output file
  fout << t + 1;

  // Return 0 to indicate successful completion
  return 0;
}
