#include <iostream>
using namespace std;
#define r 5
#define c 5

int solve(int arr[r][c]) {

    int dp[r+1][c+1] = {0};
    
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            dp[i+1][j+1] = dp[i][j+1] + dp[i+1][j] - dp[i][j] + arr[i][j];
        }
    }
    int row1 = 2;
    int col1 = 1;

    int row2 = 4;
    int col2 = 3;

    return dp[row2 + 1][col2 + 1] - dp[row1][col2 + 1] - dp[row2 + 1][col1] + dp[row1][col1];
}

int main() {

    int arr[r][c] = {
        { 3, 0, 1, 4, 2 }, 
        { 5, 6, 3, 2, 1 }, 
        { 1, 2, 0, 1, 5 }, 
        { 4, 1, 0, 1, 7 }, 
        { 1, 0, 3, 0, 5 }
    };

    cout << solve(arr);

    return 0;
}