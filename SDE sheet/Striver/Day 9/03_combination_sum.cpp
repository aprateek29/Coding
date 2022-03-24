// Given an array of distinct integers and a target, you have to 
// return the list of all unique combinations where the chosen 
// numbers sum to target. You may return the combinations in any order.

#include <iostream>
#include <vector>
#include <set>
using namespace std;

void solve(int arr[], int n, int curr, vector<int> v, set<vector<int>> &res, int target) {
    if (n == 0) {
        if (curr == target) {
            res.insert(v);
        }
        return;
    }
    if (curr > target) {
        return;
    }
    solve(arr, n-1, curr, v, res, target);
    curr = curr + arr[n-1];
    v.push_back(arr[n-1]);
    solve(arr, n, curr, v, res, target);
}

int main() {

    int arr[] = {2, 3, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 7;

    set<vector<int>> res;
    vector<int> v;
    int curr = 0;
    solve(arr, n, curr, v, res, target);

    for (auto vec : res) {
        for (auto i : vec) {
            cout << i << " ";
        }
        cout << endl;
    }


    return 0;
}