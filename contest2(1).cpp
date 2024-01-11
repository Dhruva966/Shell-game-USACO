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
    std::string number;
    long N, nights;

    long minimumdepth = LONG_MAX;

 
    cin >> N;

    cin.ignore();

    getline(std::cin, number);

    vector<long> cows;
    vector<long> sick(N, 0);

    long j = 1;

    for (char c : number) {

        if (isdigit(c)) {

            int digit = c - '0';

            cows.push_back(digit);
        }
    }

    
    for (int h = 0; h < cows.size(); h++) {

        if (cows[h] == 1) {

            sick[j]++;

        } else {

            j++;

        }
    }


    for (long k = 1; k <= j; k++) {

        if(sick[k] != 0){
        if (sick[k] % 2 == 0) {

            nights = sick[k] / 2;

        } else {

            nights = (sick[k] + 1) / 2;

        }

        minimumdepth = min(nights, minimumdepth);

    }

    }
    if((cows[0] == 1 && cows[1] == 0) || (cows[cows.size()-1] == 1 && cows[cows.size()-2] == 0)){

        minimumdepth = 1;

    }

    int r = 0;

    for (int s = 1; s <= j; s++) {

        if(sick[s] != 0){

        r += (sick[s] - (2 * minimumdepth - 2));
    
        }

    }

    cout << r;

    return 0;
}