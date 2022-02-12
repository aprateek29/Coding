#include <iostream>
#include <queue>
using namespace std;

int main() {

    priority_queue<int, vector<int>, greater<int>> minH;

    int arr[] = {6, 5, 3, 2, 8, 10, 9};
    int k = 3;
    int size = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < size; i++) {
        minH.push(arr[i]);
        if (minH.size() > k) {
            cout << minH.top() << " ";
            minH.pop();
        }
    }

    while (!minH.empty()) {
        cout << minH.top() << " ";
        minH.pop();
    }

    return 0;
}