#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main() {

    int arr[] = {1, 3, 2, 4};
    int size = sizeof(arr) / sizeof(arr[0]);

    vector<int> v;
    stack<int> s;

    for (int i = 0; i < size; i++) {
        while (!s.empty() && arr[i] > s.top()) {
            s.pop();
        }

        if (s.size() == 0) {
            v.push_back(-1);
        } else {
            v.push_back(s.top());
        }
        s.push(arr[i]);
    }

    for (auto i : v) {
        cout << i << " ";
    }

    return 0;
}