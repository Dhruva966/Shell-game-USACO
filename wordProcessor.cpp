// Source: https://usaco.guide/general/io

#include <bits/stdc++.h> // Include the necessary libraries for standard input and output operations.
#include <iostream> // Include the input/output stream library.
//#include <fstream> // Commented out, but typically used for file input/output operations.
#include <vector> // Include the vector library for managing dynamic arrays.
#include <string> // Include the string library for handling text.
#include <sstream> // Include the stringstream library for string manipulation.
using namespace std;

int main() {
    ifstream fin("word.in"); // Input stream for reading.
    ofstream fout("word.out"); // Output stream for writing.

    string essay; // Initialize a string variable to store the essay text.

    int n, k; // Initialize integer variables n and k.

    fin >> n >> k; // Read the values of n and k from input.

    int word_length = 0; // Initialize a variable to keep track of the current line's character count.

    for (int i = 0; i < n; i++){ // Iterate through each word in the essay.
        string word; // Initialize a string variable to store the current word.
        fin >> word; // Read the word from input.

        word_length += word.length(); // Add the length of the current word to the line's character count.

        if((word_length <= k)){ // Check if the current line can accommodate the word.
            if(i > 0){
                fout << " "; // Output a space if it's not the first word on the line.
            }
            fout << word; // Output the word.
        } else { // If the word doesn't fit on the current line:
            fout << "\n" << word; // Start a new line and output the word.
            word_length = word.length(); // Reset the line's character count to the word's length.
        }
    }

    return 0; // End of the program.
}
