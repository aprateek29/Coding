// Longest Repeating Subsequence
// Given a string, print the longest repeating subsequence 
// such that the two subsequence don't have same string 
// character at same position, i.e., any i'th character 
// in the two subsequences shouldn't have the same index in the original string.
// Example:
// Input: str = "aab"
// Output: "a"
// The two subsequence are 'a'(first) and 'a' 
// (second). Note that 'b' cannot be considered 
// as part of subsequence as it would be at same
// index in both.

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
            if (X[i-1] == Y[j-1] && i!=j) {
                t[i][j] = t[i-1][j-1] + 1;
            } else {
                t[i][j] = max(t[i][j-1], t[i-1][j]);
            }
        }
    }
    return t[n][m];
}

int main() {

    string X = "AABEBCDD";
    string Y = X;
    int n = X.size();
    int m = n;

    cout << solve(X, Y, n, m);

    return 0;
}