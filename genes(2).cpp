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

ifstream fin("cownomics.in");
ofstream fout("cownomics.out");

int N, M;
int tempcount = 0;
int count1 = 0;

set<int> tempset;
set<int> tempset2;

fin >> N >> M;

vector<string> spotty(M);
vector<string> plain(M);
vector<vector<int>> S(N, vector<int>(M));
vector<vector<int>> P(N, vector<int>(M));

for(int i = 0; i < N; i++){

    fin >> spotty[i];

    for(int u = 0; u < M; u++){

        if(spotty[i][u] == 'A'){

            S[i][u] = 0;

        } else if(spotty[i][u] == 'C'){

            S[i][u] = 1;

        } else if(spotty[i][u] == 'T'){

            S[i][u] = 2;

        } else if(spotty[i][u] == 'G'){

            S[i][u] = 3;

        }

    }

}

for(int i = 0; i < N; i++){

    fin >> plain[i];

    for(int u = 0; u < M; u++){

        if(plain[i][u] == 'A'){

            P[i][u] = 0;

        } else if(plain[i][u] == 'C'){

            P[i][u] = 1;

        } else if(plain[i][u] == 'T'){

            P[i][u] = 2;

        } else if(plain[i][u] == 'G'){

            P[i][u] = 3;

        }

    }

}

for(int k = 0; k < M; k++){

    for(int y = 0; y < N; y++){

        for(int j = 0; j < N; j++){

            if(S[y][k] == P[j][k]){

                tempcount++;

            } else { continue; }

            break;
        }

        if(tempcount != 0){

            break;

        }
        
    }

    if(tempcount == 0){

        count1++;

    }

    tempcount = 0;

}

fout << count1;

return 0;

}
