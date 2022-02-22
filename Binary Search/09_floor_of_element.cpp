#include <iostream>
using namespace std;

int main() {

    int arr[] = {1, 2, 3, 4, 5, 8, 10, 10, 12, 19};
    int n = sizeof(arr) / sizeof(arr[0]);

    int low = 0;
    int high = n - 1;
    int ans = -1;
    int x = 7;
    int mid;

    while (low <= high) {
        mid = low + (high - low) / 2;
        if (arr[mid] == x) {
            cout << mid << endl;
            break;
        } else if (arr[mid] > x) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    cout << low << mid << high << endl;

    return 0;
}