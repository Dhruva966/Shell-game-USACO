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
ifstream fin("censor.in");
ofstream fout("censor.out");


string text, censor;


//fout << text[i];


string result = "";


fin >> text >> censor;


for(int i = 0; i < text.size(); i++){


result += text[i];


if(result.size() >= censor.size() && result.substr(result.size() - censor.size(), censor.size()) == censor){


result.resize(result.size() - censor.size());


}


}


fout << result;


return 0;
}



