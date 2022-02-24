// Longest Common Subsequence Problem solution using recursion
// Given two sequences, find the length of longest 
// subsequence present in both of them.
// A subsequence is a sequence that appears in the same 
// relative order, but not necessarily contiguous. 

// For example, “abc”,  “abg”, “bdf”, “aeg”,  ‘”acefg”, .. etc are subsequences of “abcdefg”.

#include <iostream>
#include <string>
using namespace std;

int solve(string X, string Y, int n, int m) {

    int t[n+1][m+1];

    for (int i = 0; i < n+1; i++) {
        for (int j = 0; j < m+1; j++) {
            if (i == 0 || j == 0) {
                t[i][j] = 0;
            }
        }
    }

    for (int i = 1; i < n+1; i++) {
        for (int j = 1; j < m+1; j++) {
            if (X[i-1] == Y[j-1]) {
                t[i][j] = 1 + t[i-1][j-1];
            } else {
                t[i][j] = max(t[i-1][j], t[i][j-1]);
            }
        }
    }
    return t[n][m];
}

int main() {

    string X = "abcdgh";
    string Y = "abedfhr";
    int n = X.size();
    int m = Y.size();

    cout << solve(X, Y, n, m);

    return 0;
}