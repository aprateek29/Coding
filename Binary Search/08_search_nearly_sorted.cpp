#include <iostream>
using namespace std;

int main() {

    int arr[] = {5, 10, 30, 20, 40};
    int n = sizeof(arr) / sizeof(arr[0]);

    int low = 0;
    int high = n - 1;
    int mid;
    // int x = 5;
    // int x = 10;
    // int x = 30;
    // int x = 20;
    int x = 40;

    while (low <= high) {
        mid = low + (high - low) / 2;
        if (arr[mid] == x) {
            cout << mid << endl;
            break;
        }
        else if (mid-1 > -1 && arr[mid-1] == x) {
            cout << mid-1 << endl;
            break;
        } else if (mid+1 < n && arr[mid+1] == x) {
            cout << mid+1 << endl;
            break;
        } else if(arr[mid] > x) {
            high = mid - 2;
        } else {
            low = mid + 1;
        }
    }

    return 0;
}