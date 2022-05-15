#include <iostream>
#include <climits>
using namespace std;

int solve(int arr[], int n, int target) {

    if (target == 0) return 1;
    if (n == 0) return 0;

    if (arr[n-1] > target) {
        return solve(arr, n-1, target);
    } else {
        return solve(arr, n, target-arr[n-1]) + solve(arr, n-1, target);
    }
}

int main() {

    int arr[] = {1, 2, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    int target = 4;
    cout << solve(arr, n, target);

    return 0;
}