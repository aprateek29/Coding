#include <iostream>
using namespace std;

int solve(int t, int r, int range) {

    int dp[r+1][t+1];
    for (int i = 0; i < r+1; i++) {
        for (int j = 0; j < t+1; j++) {
            if (i == 0 && j == 0) {
                dp[i][j] = 1;
            } else if (i == 0 || j == 0){
                dp[i][j] = 0;
            }
        }
    }
    for (int i = 1; i < r+1; i++) {
        for (int j = 1; j < t+1; j++) {
            int count = 0;
            for (int k = 1; k <= range; k++) {
                if (j >= k)
                    count += dp[i-1][j-k];
            }
            dp[i][j] = count;
        }
    }
    return dp[r][t];
}

int main() {

    int target = 4;
    int rolls = 3;
    int range = 3;

    cout << solve(target, rolls, range);

    return 0;
}