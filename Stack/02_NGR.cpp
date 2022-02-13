#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

int main() {

    int arr[] = {1, 3, 2, 4};
    int size = sizeof(arr) / sizeof(arr[0]);

    stack<int> s;
    vector<int> v;
    for (int i = size-1; i > -1; i--) {
        while(!s.empty() && arr[i] > s.top()) {
            s.pop();
        }
        if (s.size() == 0) {
            v.push_back(-1);
        } else {
            v.push_back(s.top());
        }
        s.push(arr[i]);
    }

    reverse(v.begin(), v.end());
    for (auto i : v) {
        cout << i << " ";
    }

    return 0;
}