#include <iostream>
using namespace std;

int main() {

    int arr[] = {2, 4, 10, 10, 10, 18, 20};
    int size = sizeof(arr) / sizeof(arr[0]);

    int low = 0;
    int high = size - 1;
    int x = 10;

    int mid;
    int ans = -1;

    while (low <= high) {
        mid = low + (high - low) / 2;
        if (arr[mid] == x) {
            low = mid + 1;
            ans = mid;
        } else if (arr[mid] > x) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    cout << ans;

    return 0;
}