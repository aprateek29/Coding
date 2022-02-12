#include <iostream>
#include <map>
#include <queue>
using namespace std;

int main() {

    int arr[] = {1, 1, 1, 3, 2, 2, 4};
    int size = sizeof(arr) / sizeof(arr[0]);
    int k = 2;

    map<int, int> m; // freq, ele
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minH;

    for (int i = 0; i < size; i++) {
        if (m.count(arr[i]) == 0) {
            m[arr[i]] = 1;
        } else {
            m[arr[i]] += 1;
        }
    }

    for (auto i : m) {
        minH.push({i.second, i.first});
        if (minH.size() > k) {
            minH.pop();
        }
    }

    while(!minH.empty()) {
        cout << minH.top().second << " ";
        minH.pop();
    }


    return 0;
}