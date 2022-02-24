// Printing Longest Common Subsequence
// Given two sequences, print the longest subsequence present in both of them.
// Example:
// LCS for input Sequences “ABCDGH” and “AEDFHR” is “ADH” of length 3.

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string solve(string X, string Y, int n, int m) {
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
    string ans = "";
    int i = n;
    int j = m;
    while (i > 0 && j > 0) {
            if (X[i-1] == Y[j-1]) {
                ans += X[i-1];
                i--;
                j--;
            } else if (t[i-1][j] > t[i][j-1]) {
                i--;
            } else {
                j--;
            }
    }
    for (int i = 0; i < ans.size() / 2; i++) {
        swap(ans[i], ans[ans.size()-i-1]);
    }
    return ans;
}

int main() {

    string X = "abasfjlk;dsfjlkdsfjlkdcdjalk;sfdjlk;asfdjlk;asfdaf";
    string Y = "fasasjlk;sfdjlksfdjlk;asfdfjlk;djlkasfdasfjlk;ddjlk";
    int n = X.size();
    int m = Y.size();

    cout << solve(X, Y, n, m);

    return 0;
}