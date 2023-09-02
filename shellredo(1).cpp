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

ifstream fin("shell.in");
ofstream fout("shell.out");

int N, numpoints, maxpoints;

fin >> N;

vector<int> guesses(N);
vector<pair<int, int>> swaps(N);
vector<bool> isPebble(4, false);



maxpoints = 0;

	for(int u = 0; u < N; u++){

		fin >> swaps[u].first >> swaps[u].second >> guesses[u];

	}

	for(int start = 1; start < 4; start++){

		numpoints = 0;

		for(int i = 0; i < 4; i++){

			isPebble[i] = false;

		}

		isPebble[start] = true;

		for(int r = 0; r < N; r++){

		swap(isPebble[swaps[r].first], isPebble[swaps[r].second]);

			if(isPebble[guesses[r]]){

				numpoints++;

			}

		}

		maxpoints = max(numpoints, maxpoints);

	}

	fout << maxpoints;






















}