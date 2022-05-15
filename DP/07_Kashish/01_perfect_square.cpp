#include <iostream>
#include <climits>
using namespace std;

int solve(int n) {
    int dp[n+1];
    dp[0] = 0;
    for (int i = 1; i < n+1; i++) {
        dp[i] = i;
        for (int j = 1; j * j <= i; j++) {
            dp[i] = min(dp[i], 1+dp[i-j*j]);
        }
    }
    return dp[n];
}

int main() {

    int n = 12*11;
    cout << solve(n);

    return 0;
}