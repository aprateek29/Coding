#include <iostream>
using namespace std;

int solve(int n) {
    int dp[n+1];
    dp[0] = 0;
    for (int i = 1; i < n+1; i++) {
        dp[i] = 1;
        for (int j = 1; j < i; j++) {
            dp[i] = max( i, max(dp[i], j*dp[i-j]));
        }
    }
    return dp[n];
}

int main() {

    int n = 10;
    cout << solve(n);

    return 0;
}