#include <iostream>
using namespace std;

int main() {

    int arr[] = {0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1};
    int n = sizeof(arr) / sizeof(arr[0]);

    int low = 0;
    int high = n - 1;
    int mid;
    int ans = -1;

    while (low <= high) {
        mid = low + (high - low) / 2;
        if (arr[mid] == 1) {
            ans = mid;
            high = mid - 1;
        } else if (arr[mid] == 0) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    cout << ans << endl;

    return 0;
}