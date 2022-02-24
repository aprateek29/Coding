// Coin Change Problem Maximum Number of ways
// Given a value N, if we want to make change for N cents, 
// and we have infinite supply of each of S = { S1, S2, .. , Sm} 
// valued coins, how many ways can we make the change? 
// The order of coins doesn’t matter.
// Example:
// for N = 4 and S = {1,2,3}, there are four solutions: {1,1,1,1},{1,1,2},{2,2},{1,3}. 
// So output should be 4.

#include <iostream>
using namespace std;

int solve(int arr[], int N, int n) {
    int t[n+1][N+1];

    for (int i = 0; i < n+1; i++) {
        for (int j = 0; j < N+1; j++) {
            if (i == 0) {
                t[i][j] = 0;
            }
            if (j == 0) {
                t[i][j] = 1;
            }
        }
    }

    for (int i = 1; i < n+1; i++) {
        for (int j = 1; j < N+1; j++) {
            if (arr[i-1] > j) {
                t[i][j] = t[i-1][j];
            } else {
                t[i][j] = t[i-1][j] + t[i][j-arr[i-1]];
            }
        }
    }
    return t[n][N];
}

int main() {

    int arr[] = {1, 2, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    int N = 4;

    cout << solve(arr, N, n);

    return 0;
}