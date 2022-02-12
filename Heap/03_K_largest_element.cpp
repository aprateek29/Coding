#include<iostream>
#include<queue>
using namespace std;

int main() {

    priority_queue<int, vector<int>, greater<int>> minH;
    int k = 3;
    int arr[] = {7, 10, 4, 3, 20, 15};
    int size = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < size; i++) {
        minH.push(arr[i]);
        if (minH.size() > k) {
            minH.pop();
        }
    }

    while (!minH.empty()) {
        cout << minH.top() << " ";
        minH.pop();
    }

    return 0;
}