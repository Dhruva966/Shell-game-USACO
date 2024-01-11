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

ifstream fin("lineup.in");
ofstream fout("lineup.out");

int N;
int r = 0;
string g, h;
fin >> N;

vector<string> cows(8);
vector<pair<string, string>> values(100);

cows[0] = "Beatrice";
cows[1] = "Belinda";
cows[2] = "Bella";
cows[3] = "Bessie";
cows[4] = "Betsy";
cows[5] = "Blue";
cows[6] = "Buttercup";
cows[7] = "Sue";

sort(cows.begin(), cows.end());

for(int u = 0; u < N; u++){

	fin >> g;

    for (int i = 0; i < 4; i++) {
        
        string temp;
        fin >> temp;

    }

    fin >> h;  
	
    values[u] = make_pair(g, h);

}

while(next_permutation(cows.begin(), cows.end())){

	for(int i = 0; i < N; i++){

		auto a = find(cows.begin(), cows.end(), values[i].first);
		auto b = find(cows.begin(), cows.end(), values[i].second);

		if(abs(a - b) != 1){

			r++;

		}

	}

	if(r != 0){

		r = 0;
		continue;

	} else {

		break;

	}

}

for(auto cow : cows){

fout << cow << "\n";

}

return 0;

}