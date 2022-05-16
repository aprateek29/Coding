#include <iostream>
using namespace std;

int main() {

    char arr[] = {'a', 'c', 'f', 'h'};
    int s = sizeof(arr) / sizeof(arr[0]);

    char k = 'i';

    int l = 0;
    int h = s-1;
    int mid;
    int ans = -1;
    while (l <= h) {
        mid = l + (h-l) / 2;
        if (arr[mid] == k) {
            break;
        } else if (arr[mid] > k) {
            ans = mid;
            h = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    cout << mid << endl;

    return 0;
}