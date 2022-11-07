#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solve(int start[], int end[], int n) {
    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++) {
        v.push_back({end[i], start[i]});
    }
    sort(v.begin(), v.end());
    for (auto i : v) {
        cout << i.second << " ";
    }
    cout << endl;

    for (auto i : v) {
        cout << i.first << " ";
    }
    int count = 1;
    int curr = v[0].first;

    for (int i = 1; i < n; i++) {
        if (v[i].second > curr) {
            count++;
            curr = v[i].first;
        }
    }
    cout << endl;
    cout << count;
}

int main() {

    int start[] = {1, 3, 0, 5, 8, 5};
    int end[] = {2, 4, 6, 7, 9, 9};
    int n = sizeof(start) / sizeof(start[0]);

    solve(start, end, n);


    return 0;
}