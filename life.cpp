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

ifstream fin("lifeguards.in");
ofstream fout("lifeguards.out");

int initial = 0;
int count = 0;
int countmax = -1;
int N;

fin >> N;

vector<pair<int, int>> times(N);
vector<int> lifeguards(1000, 0);

for(int i = 0; i < N; i++){

    fin >> times[i].first >> times[i].second;

    for(int j = times[i].first; j < times[i].second; j++){

        lifeguards[j]++;
        initial = max(initial, j);
        
    }

}

for(int p = 0; p < N; p++){

    for(int k = times[p].first; k < times[p].second; k++){

        lifeguards[k]--;

    }

    for(int m = 0; m < initial + 1; m++){

        if(lifeguards[m] > 0){

            count++;

        }

    }

    countmax = max(countmax, count);

    count = 0;

    for(int h = times[p].first; h < times[p].second; h++){

        lifeguards[h]++;

    }

}

fout << countmax;

return 0;

}
	
