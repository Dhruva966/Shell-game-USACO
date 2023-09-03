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
	
//ifstream fin("mixmilk.in");

//ofstream fout("mixmilk.out");



	    vector<pair<long long, long long>> milks(3); // Creating a vector to store the pairs

  for (int i = 0; i < 3; i++) {
        long long a, b;
        cin >> a >> b;
        milks[i] = make_pair(a, b);
    }


for(int e = 0; e < 2; e++){
		for(int u = 0; u < 3; u++){
			
			if(u == 2){

				milks[0].second += milks[2].second;
				milks[2].second = 0;

				if(milks[0].second > milks[0].first){

				milks[2].second += (milks[0].second - milks[0].first);

				milks[0].second = milks[0].first;
				
				}

			} else{
			
			milks[u+1].second += milks[u].second;
			milks[u].second = 0;

			if(milks[u+1].second > milks[u+1].first){

				milks[u].second += (milks[u+1].second - milks[u+1].first);
				milks[u+1].second = milks[u+1].first;
			} 

		}

		}
		
}

	milks[1].second += milks[0].second;
			milks[0].second = 0;

			if(milks[1].second > milks[1].first){

				milks[0].second += (milks[1].second - milks[1].first);
				milks[1].second = milks[1].first;
			}


				cout << milks[0].second << "\n" << milks[1].second << "\n" << milks[2].second;




}

