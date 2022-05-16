#include <iostream>
using namespace std;

int main() {

    int r = 4;
    int c = 4;
    int arr[r][c] = {
        {10, 20, 30, 40},
        {15, 25, 35, 45},
        {27, 29, 37, 48},
        {32, 33, 39, 50},
    };

    int k = 28;
    int i = 0;
    int j = c-1;

    while (arr[i][j] != k && j >= 0 && i < r) {
        if (arr[i][j] > k) {
            j--;
        } else {
            i++;
        }
    }
    cout << i << ", " << j << endl;

    return 0;
}