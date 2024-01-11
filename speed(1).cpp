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

ifstream fin("speeding.in");
ofstream fout("speeding.out");

int N, M;
int maxin = 0;
int o = 0;
int r = 0;

vector<int> limits(1000);

fin >> N >> M;

vector<pair<int, int>> journey(1000);
vector<pair<int, int>> segment(1000);

for(int i = 0; i < N; i++){

	fin >> segment[i].first >> segment[i].second;

}

for(int u = 0; u < M; u++){

	fin >> journey[u].first >> journey[u].second;

}

for(int m = 0; m < N; m++){

	for(int y = 0; y < segment[m].first; y++){

		limits[y + o] = segment[m].second;

	}

	o += segment[m].first;

}

for(int p = 0; p < M; p++){

	for(int z = 0; z < journey[p].first; z++){

		if(limits[z + r] < journey[p].second){

			maxin = max((journey[p].second - limits[z + r]), maxin);

		}

	}

	r += journey[p].first;

}

fout << maxin;

return 0;

}