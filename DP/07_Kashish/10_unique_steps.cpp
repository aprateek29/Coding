#include <iostream>
using namespace std;
#define r 3
#define c 3

int solve(int grid[r][c], int i, int j) {
    if ( i < 0 || j < 0 || grid[i][j] == 1) {
        return 0;
    }

    int dp[r+1][c+1];
    for (int i = 0; i < r+1; i++) {
        for (int j = 0; j < c+1; j++) {
            if (i == 0 && j == 0) {
                dp[i][j] = 1;
            } else if (i == 0 || j == 0) {
                return 0;
            }
        }
    }

    if (i == 0 && j == 0) {
        return 1;
    }
    return solve(grid, i-1, j) + solve(grid, i, j-1);
}

int main() {

    int grid[r][c] = {
        {0,0,0},
        {0,1,0},
        {0,0,0}
    };

    cout << solve(grid, r-1, c-1);

    return 0;
}