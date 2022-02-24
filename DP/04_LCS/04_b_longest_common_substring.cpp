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
                t[i][j] = 0;
            }
        }
    }

    return t[n][m];
}

int main() {

    string X = "abcde";
    string Y = "abfde";

    int n = X.size();
    int m = Y.size();

    cout << solve(X, Y, n, m);

    return 0;
}