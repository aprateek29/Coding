#include <iostream>
#include <cstring>
using namespace std;
int t[11][11];

int solve(int wt[], int val[], int W, int n) {
    if (n == 0 || W == 0) {
        return 0;
    }
    if (t[n][W] != -1) {
        return t[n][W];
    }
    if (wt[n-1] > W) {
        t[n][W] = solve(wt, val, W, n-1);
        return t[n][W];
    } else {
        t[n][W] = max(val[n-1] + solve(wt, val, W-wt[n-1], n-1), solve(wt, val, W, n-1));
        return t[n][W];
    }
}

int main() {

    memset(t, -1, sizeof(t));
    int wt[] = {1, 3, 4, 5};
    int val[] = {1, 4, 5, 7};
    int W = 7;
    int n = 4;
    cout << solve(wt, val, W, n);


    return 0;
}