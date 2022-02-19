// Key Points - Will use backtracking
// Will work for duplicate elements also

// Question - Find all subset of given set
// {1, 2, 3}

#include <iostream>
#include <vector>
#include <set>
using namespace std;

void solve(int index, int arr[], int n, set<vector<int>> &sets, vector<int> &curr) {
    if (index == n) {
        sets.insert(curr);
        return;
    }
    solve(index+1, arr, n, sets, curr);
    curr.push_back(arr[index]);
    solve(index+1, arr, n, sets, curr);
    curr.pop_back();

}

int main() {

    int arr[] = {1, 2, 3};
    // int arr[] = {1, 2, 2};
    int size = sizeof(arr) / sizeof(arr[0]);
    set<vector<int>> sets;
    vector<int> curr;
    int i = 0;
    solve(i, arr, size, sets, curr);

    for (auto vec : sets) {
        for (auto i : vec) {
            cout << i << " ";
        }
        cout << endl;
    }


    return 0;
}