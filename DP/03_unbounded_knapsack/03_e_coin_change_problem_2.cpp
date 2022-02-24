// Coin Change Problem Minimum Numbers of coins
// Given a value V, if we want to make change for V cents, 
// and we have infinite supply of each of C = { C1, C2, .. , Cm} valued coins,
// what is the minimum number of coins to make the change?
// Example:

// Input: coins[] = {25, 10, 5}, V = 30
// Output: Minimum 2 coins required
// We can use one coin of 25 cents and one of 5 cents
#include <iostream>
#include <climits>
using namespace std;

int solve(int arr[], int V, int n) {
    int t[n+1][V+1];
    for (int i = 0; i < n+1; i++) {
        for (int j= 0; j < V+1; j++) {
            if (i == 0) {
                t[i][j] = INT_MAX - 1;
            }
            if (j == 0) {
                t[i][j] = 0;
            }
        }
    }

    for (int i = 1; i < n+1; i++) {
        for (int j = 1; j < V+1; j++) {
            if (arr[i-1] > j) {
                t[i][j] = t[i-1][j];
            } else {
                t[i][j] = min(t[i-1][j], 1+t[i][j-arr[i-1]]);
            }
        }
    }

    return t[n][V];
}

int main() {

    int arr[] = {25, 10, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int V = 30;

    cout << solve(arr, V, n);

    return 0;
}