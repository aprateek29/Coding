// Equal Sum Partition Problem
// Partition problem is to determine whether a given set can be partitioned into two subsets such that the sum of elements in both subsets is same.
// Examples:

// arr[] = {1, 5, 11, 5}
// Output: true 
// The array can be partitioned as {1, 5, 5} and {11}
#include <iostream>
using namespace std;

bool solve(int arr[], int s, int n) {
    bool t[n+1][s+1];

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
                t[i][j] = t[i-1][j] || t[i-1][j-arr[i-1]];
            }
        }
    }
    return t[n][s];
}


int main() {

    int arr[] = {1, 5, 2, 5};
    int n = 4;

    // my code

    int s = 0;
    for (int i = 0; i < n; i++) {
        s += arr[i];
    }
    if (s % 2 == 0) {
        s = s / 2; 
        cout << solve(arr, s, n);
    } else {
        cout << 0 << endl;
    }


    return 0;
}