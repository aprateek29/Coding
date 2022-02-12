#include <iostream>
#include <queue>
using namespace std;

int main() {
    priority_queue<int> maxH;
    int k = 3;
    int arr[] = {7, 10, 4, 3, 20, 15};
    int size = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < size; i++) {
        maxH.push(arr[i]);
        if (maxH.size() > k) {
            maxH.pop();
        }
    }
    
    cout << maxH.top() << endl;

    return 0;
}