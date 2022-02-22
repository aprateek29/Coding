#include <iostream>
using namespace std;

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int size = sizeof(arr) / sizeof(arr[0]);

    int low = 0;
    int high = size - 1;
    int x=2;
    int mid;
    while (low <= high) {
        mid = low + (high-low)/2;
        if (arr[mid] == x) {
            cout << "Found " << arr[mid] << " at " << mid;
            break;
        } else if(arr[mid] > x) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
}