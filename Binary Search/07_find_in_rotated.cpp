#include <iostream>
using namespace std;

int binarySearch(int arr[], int low, int high, int x) {
    int mid;
    int res = -1;

    while (low <= high) {
        mid = low + (high - low) / 2;
        if (arr[mid] == x) {
            res = mid;
            break;
        } else if (arr[mid] > x) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return res;
}

int findIndex(int arr[], int N) {
    int low = 0;
    int high = N - 1;

    int mid;
    int prev;
    int next;

    while (low <= high) {
        mid = low + (high - low) / 2;
        prev = (N + mid - 1) % N;
        next = (mid - 1) % N;
        if (arr[mid] <= arr[prev] && arr[mid] <= arr[next]) {
            return mid;
        } else if (arr[mid] <= arr[high]) {
            high = mid - 1;
        } else if (arr[low] <= arr[mid]) {
            low = mid + 1;
        }
    }
}

int main() {
    // int arr[] = {2, 5, 6, 8, 11, 12, 15, 18}; // 0
    // int arr[] = {18, 2, 5, 6, 8, 11, 12, 15}; // 1
    // int arr[] = {15, 18, 2, 5, 6, 8, 11, 12}; // 2
    // int arr[] = {12, 15, 18, 2, 5, 6, 8, 11}; // 3
    int arr[] = {11, 12, 15, 18, 2, 5, 6, 8}; // 4
    // int arr[] = {8, 11, 12, 15, 18, 2, 5, 6}; // 5
    // int arr[] = {6, 8, 11, 12, 15, 18, 2, 5}; // 6
    // int arr[] = {5, 6, 8, 11, 12, 15, 18, 2}; // 7
    // int arr[] = {2, 1}; // only 2 elements
    int N = sizeof(arr) / sizeof(arr[0]);

    int index = findIndex(arr, N);
    int ans1 = binarySearch(arr, 0, index-1, 16);
    int ans2 = binarySearch(arr, index, N-1, 16);

    if (ans1 != -1) {
        cout << ans1;
    } else if (ans2 != -1){
        cout << ans2;
    } else {
        cout << -1;
    }

        return 0;
}