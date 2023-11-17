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

ifstream fin("guess.in");
ofstream fout("guess.out");

int N;
int t = 0;
int x = 0;
int m = 0;
int y = 0;

fin >> N;

vector<vector<string>> characteristics(N, vector<string>(1));
vector<string> name(N);

for(int i = 0; i < N; i++){

	int p;

	fin >> name[i] >> p;
	characteristics[i].resize(p);

	for(int j = 0; j < p; j++){

		fin >> characteristics[i][j];

	}

}

for(int z = 0; z < N-1; z++){

	for(int v = z + 1; v < N; v++){

		for(auto it : characteristics[z]){

			for(auto u : characteristics[v]){

				if(characteristics[z][y] == characteristics[v][m]){

					x++;

				}

				m++;

			}
			
			m = 0;

			y++;

		}

		y = 0;

		t = max(t, x);
		x = 0;

	}

}

fout << t + 1;

}

