// same as target sum

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

    int arr[] = {1, 1, 2, 3};
    int diff = 1;
    int n = sizeof(arr) / sizeof(arr[0]);

    int s = 0;
    for (int i = 0; i < n; i++) {
        s += arr[i];
    }

    int s1 = (s-diff)/2;

    cout << solve(arr, s1, n);

    return 0;
}