#include <iostream>
#include <queue>
using namespace std;

int main() {

    priority_queue<pair<int, int>> maxH; // diff, number

    int arr[] = {5, 6, 7, 8, 9};
    int k = 3;
    int x = 7;
    int size = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < size; i++) {
        maxH.push({abs(arr[i] - x), arr[i]});
        if (maxH.size() > k) {
            maxH.pop();
        }
    }

    while (!maxH.empty()) {
        cout << maxH.top().second << " ";
        maxH.pop();
    }

    return 0;
}