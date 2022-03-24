// Problem Statement : Given an array of integers that may 
// contain duplicates the task is to return all possible subsets.
// Return only unique subsets and they can be in any order.

#include <iostream>
#include <set>
#include <vector>
using namespace std;

void solve(int arr[], int n, vector<int> v, set<vector<int>> &res) {
    if (n == 0) {
        res.insert(v);
        return;
    }
    solve(arr, n-1, v, res);
    v.push_back(arr[n-1]);
    solve(arr, n-1, v, res);
}

int main() {

    int arr[] = {1, 2, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    vector<int> v;
    set<vector<int>> res;
    solve(arr, n, v, res);

    for (auto i : res) {
        for (auto j : i) {
            cout << j << " ";
        }
        cout << endl;
    }

    return 0;
}