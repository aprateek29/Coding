#include <iostream>
#include <queue>
using namespace std;

int main() {

    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    priority_queue<int, vector<int>, greater<int>> minH;

    for (int i = 0; i < size; i++) {
        minH.push(arr[i]);
    }

    while (minH.size() != 1) {
        int first = minH.top();
        minH.pop();
        int second = minH.top();
        minH.pop();
        minH.push(first + second);
    }

    cout << minH.top() << " ";

    return 0;
}