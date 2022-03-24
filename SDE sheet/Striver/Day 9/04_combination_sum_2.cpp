#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;



int main() {

    int arr[] = {10,1,2,7,6,1,5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 8;
    sort(arr, arr+n);
    vector<int> curr;
    set<vector<int>> all;

    int i = 0;
    int currS = 0;

    solve(i, arr, n, target, currS, curr, all);

    for (auto v : all) {
        for (auto i : v) {
            cout << i << " ";
        }
        cout << endl;
    }

    return 0;
}