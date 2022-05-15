#include <iostream>
using namespace std;

int solve(int arr[], int n) {

    int maxProfit = 0;
    int minElement = arr[0];
    for (int i = 0; i < n; i++) {
        maxProfit = max(maxProfit, arr[i]-minElement);
        minElement = min(minElement, arr[i]);
    }

    return maxProfit;
}

int main() {

    int arr[] = {6, 2, 4, 3, 10, 7, 19};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout << solve(arr, n);

    return 0;
}