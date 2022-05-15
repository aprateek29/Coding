#include <iostream>
using namespace std;

int solve(int n) {
    int dp[101];
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 5;
    for (int i = 4; i <= n; i++) 
        dp[i] = dp[i-3] + 2*dp[i-1];

    return dp[n];
}

int main() {

    int n = 4;
    cout << solve(n);

    return 0;
}