#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>
using namespace std;

int main() {

    vector<int> v;
    stack<pair<int, int>> s; // ind, ele

    int arr[] = {100, 80, 60, 70, 60, 75, 85};
    int size = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < size; i++) {
        while (!s.empty() && arr[i] >= s.top().second) {
            s.pop();
        }

        if (s.size() == 0) {
            v.push_back(-1);
        } else {
            v.push_back(s.top().first);
        }
        s.push({i, arr[i]});
    }


    for (int i = 0; i < size; i++) {
        cout << i - v[i] << " ";
    }

    return 0;
}