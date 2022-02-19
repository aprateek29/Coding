#include <iostream>
#include <vector>
#include <set>
using namespace std;

void solve(int pos, int arr[], int n, set<vector<int>> &sets, vector<int> &curr, int target, int &currS) {
    if (currS == target) {
        sets.insert(curr);
        return;
    }
    if (currS > target || pos == n) {
        return;
    }
    solve(pos+1, arr, n, sets, curr, target, currS);
    curr.push_back(arr[pos]);
    currS += arr[pos];
    solve(pos, arr, n, sets, curr, target, currS);
    currS -= arr[pos];
    curr.pop_back();
}

int main() {
    int arr[] = {1, 2, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    int target = 4;
    int pos = 0;
    set<vector<int>> sets;
    vector<int> curr;
    int currS = 0;
    solve(pos, arr, n, sets, curr, target, currS);

    for (auto vec : sets) {
        for (auto i : vec) {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}