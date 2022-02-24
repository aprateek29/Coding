// Subset Sum Problem(Dynamic Programming)
// Given a set of non-negative integers, and a value sum, determine if there is a subset of the given set with sum equal to given sum.
// Example:

// Input:  set[] = {3, 34, 4, 12, 5, 2}, sum = 9
// Output:  True  //There is a subset (4, 5) with sum 9.

#include <iostream>
#include <cstring>
using namespace std;

bool solve(int set[], int s, int n) {
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
            if (set[i-1] > j) {
                t[i][j] = t[i-1][j];
            } else {
                t[i][j] = t[i-1][j] || t[i-1][j-set[i-1]];
            }
        }
    }
    return t[n][s];
}

int main() {

    int set[] = {3, 34, 14, 12, 5, 2};
    int s = 9;
    int n = sizeof(set) / sizeof(set[0]);

    cout << solve(set, s, n);

    return 0;
}