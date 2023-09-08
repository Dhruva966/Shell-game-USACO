#include <bits/stdc++.h>  // Include necessary libraries
using namespace std;
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <cmath>

int main() {
    ifstream fin("censor.in");  // Open input file "censor.in" for reading
    ofstream fout("censor.out");  // Open output file "censor.out" for writing

    string text, censor;  // Declare two strings to store input text and censor string

    string result = "";  // Declare a string to store the result after censoring

    fin >> text >> censor;  // Read the input text and censor string from the input file

    for(int i = 0; i < text.size(); i++){  // Loop through each character in the input text
        result += text[i];  // Add the current character to the result string

        // Check if the result string has become long enough to potentially contain the censor string,
        // and if the last part of the result string matches the censor string
        if(result.size() >= censor.size() && result.substr(result.size() - censor.size(), censor.size()) == censor){
            result.resize(result.size() - censor.size());  // Remove the last part of the result string that matches the censor string
        }
    }

    fout << result;  // Write the final result string to the output file

    return 0;  // Return 0 to indicate successful program execution
}
