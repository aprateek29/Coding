#include <iostream>
#include <climits>
#include <cstring>
using namespace std;


int solve(int arr[], int n) {
    int a = 0;
    int b = arr[0];
    int c;
    for (int i = 2; i <= n; i++) {
        c = arr[i-1] + min(a, b);
        a = b;
        b = c;
    }
    return c;
}

int main() {
    int arr[] = {3, 5, 4, 1, 8, 1, 4, 3, 9, 9, 3, 1, 10, 49, 39, 2, 1, 4, 39, 3, 1, 4, 3, 2, 4, 34, 2, 1, 4, 9, 9, 34, 29843, 198, 9, 3, 1, 43434, 984394, 39843, 24,245,245 ,45245, 4543,2541,45 ,43254,54};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << solve(arr, n);

    return 0;
}