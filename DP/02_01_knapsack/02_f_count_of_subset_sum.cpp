// Count of subsets sum with a Given sum
// Given an array arr[] of length N and an integer X, the task is to find the number of subsets with sum equal to X.
// Example:

// Input: arr[] = {1, 2, 3, 3}, X = 6
// Output: 3
// All the possible subsets are {1, 2, 3},
// {1, 2, 3} and {3, 3}
#include <iostream>
using namespace std;

int solve(int arr[], int s, int n) {
    int t[n+1][s+1];
    for (int i = 0; i < n+1; i++) {
        for (int j = 0; j < s+1; j++) {
            if (i == 0) {
                t[i][j] = 0;
            }
            if (j == 0) {
                t[i][j] = 1;
            }
        }
    }

    for (int i = 1; i < n+1; i++) {
        for (int j = 1; j < s+1; j++) {
            if (arr[i-1] > j) {
                t[i][j] = t[i-1][j];
            } else {
                t[i][j] = t[i-1][j] + t[i-1][j-arr[i-1]];
            }
        }
    }
    return t[n][s];
}

int main() {

    int arr[] = {2, 3, 5, 6, 8, 10};
    int s = 10;
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << solve(arr, s, n);

    return 0;
}