#include <iostream>
using namespace std;

int main() {
    int arr[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int size = sizeof(arr) / sizeof(arr[0]);
    int low = 0;
    int high = size - 1;
    int mid;
    int x = 2;
    while (low <= high) {
        mid = low + (high - low) /2;
        if (arr[mid] == x) {
            cout << "Found " << arr[mid] << " at " << mid;
            break;
        } else if(arr[mid] > x) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return 0;
}