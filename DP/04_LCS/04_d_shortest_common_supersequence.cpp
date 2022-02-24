// Shortest Common Supersequence
// Given two strings str1 and str2, find the shortest string 
// that has both str1 and str2 as subsequences.
// Examples:

// Input:   str1 = "geek",  str2 = "eke"
// Output: "geeke"

// mine
// X = "gtab";
// y = "gt";
// lcs = gt
// Scs = gtab ( length(X) + length(Y) - lcs)

#include <iostream>
#include <string>
using namespace std;

int solve(string X, string Y, int n, int m) {
    // just return m + n - lcs (longest common supersequence)
}

int main() {

    string X = "geek";
    string Y = "eke";
    int n = X.size();
    int m = Y.size();

    cout << solve(X, Y, n, m);

    return 0;
}