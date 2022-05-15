#include <iostream>
using namespace std;

int solve(int n, int m) {
    if (n == 0) return 0;
    if (n == 1) return 1;

    if (n < m) {
        return solve(n-1, m);
    }
    return solve(n-1, m) + solve(n-m, m);
}

int main() {

    int n = 5;
    int m = 3;
    cout << solve(n, m);

    return 0;
}