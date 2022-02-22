// in second if statement doubt

// when 1 and 2 if change then wrong result

#include <iostream>
using namespace std;

int main() {

    int arr[] = {11, 12, 15, 18, 2, 5, 6, 8};
    int N = sizeof(arr) / sizeof(arr[0]);

    int low = 0;
    int high = N - 1;
    int mid;

    int prev;
    int next;

    while (low <= high) {
        mid = low + (high - low) /2 ;
        prev = (N + mid - 1) % N;
        next = (mid + 1) % N;

        cout << prev << mid << next << endl;

        if (arr[mid] < arr[prev] && arr[mid] < arr[next]) {
            cout << mid;
            break;
        } else if (arr[mid] < arr[high]) {
            high = mid - 1;
        } else if (arr[low] < arr[mid]) {
            low = mid + 1;
        }
    }

    return 0;
}