// Rod Cutting Problem
//  Given a rod of length n inches and an array of prices that contains 
// prices of all pieces of size smaller than n. Determine the  maximum value 
// obtainable by cutting up the rod and selling the pieces. 
// Example: 
// if length of the rod is 8 and the values of different pieces are given 
// as following, then the maximum obtainable value is 22 
// (by cutting in two pieces of lengths 2 and 6)

// int N = 8
// length   | 1   2   3   4   5   6   7   8  
// --------------------------------------------
// price    | 1   5   8   9  10  17  17  20

#include <iostream>
using namespace std;

int solve(int l[], int p[], int N, int n) {
    int t[n+1][N+1];
    for (int i = 0; i < n+1; i++) {
        for (int j = 0; j < N+1; j++) {
            if (i == 0 || j == 0) {
                t[i][j] = 0;
            }
        }
    }

    for (int i = 1; i < n+1; i++) {
        for (int j = 1; j < N+1; j++) {
            if (l[i-1] > j) {
                t[i][j] = t[i-1][j];
            } else {
                t[i][j] = max(p[i-1] + t[i][j-l[i-1]], t[i-1][j]);
            }
        }
    }
    return t[n][N];
}

int main() {

    int l[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int p[] = {1, 5, 8, 9, 10, 17, 17, 20};

    int n = sizeof(l) / sizeof(l[0]);
    int N = 8;

    cout << solve(l, p, N, n);


    return 0;
}