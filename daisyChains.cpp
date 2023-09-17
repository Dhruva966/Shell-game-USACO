// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <cmath>

int main() {

  int N, count, count1;

  cin >> N;  // Read the number of flowers.

  vector<int> flowers(N);  // Create a vector to store the petals of each flower.

  // Read the number of petals for each flower.
  for(int i = 0; i < N; i++){
    cin >> flowers[i];
  }

  count = N;  // Initialize the count with the total number of flowers.

  for(int u = 0; u < N; u++){

    count1 = flowers[u];  // Initialize count1 with the petals of the current flower.

    for(int j = 0; j < (N-u); j++){

      count1 += flowers[u+j+1];  // Calculate the sum of petals for the current range.

      // Check if the average of petals is an integer and exists in the current range.
      if(count1 % (j+2) == 0){

        for(int k = u; k < (u+j+1); k++){

          // If the average exists in the range, increment the count.
          if(count1/(j+2) == flowers[k]){
            count++;
          }

        }

      } else {
        continue;  // Move to the next iteration if the average is not an integer.
      }

    }

  }

  cout << count;  // Print the total count of photos with an average flower.

  return 0;

}
