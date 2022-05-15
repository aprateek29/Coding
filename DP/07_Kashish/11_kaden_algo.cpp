#include <iostream>
using namespace std;

int solve(int arr[], int n) {
    int dp[n+1];
    dp[0] = 0;
    for (int i = 1; i < n+1; i++) {
        dp[i] = arr[i-1];
        dp[i] =  max(dp[i], dp[i-1] + arr[i-1]);
    }
}

int main() {
    int arr[] = {-1, 4, 2, -5, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << solve(arr, n);
    return 0;
}