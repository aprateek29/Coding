#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>
using namespace std;

int main() {

    vector<int> v;
    stack<int> s;

    int arr[] = {100, 80, 60, 70, 60, 75, 85};
    int size = sizeof(arr) / sizeof(arr[0]);

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