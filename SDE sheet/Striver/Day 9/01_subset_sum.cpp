// Problem Statement : Given an array print all the sum of the 
// subset generated from it, in the increasing order.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solve(int arr[], int n, int curr, vector<int> &total) {
    if (n == 0) {
        total.push_back(curr);
        return;
    }
    solve(arr, n-1, curr, total);
    curr += arr[n-1];
    solve(arr, n-1, curr, total);
}

int main() {

    int arr[] = {3, 2, 1};
    int n = 3;
    int curr = 0;
    vector<int> total;
    sort(arr, arr+n);
    solve(arr, n, curr, total);

    for (auto i : total) {
        cout << i << " ";
    }

    return 0;
}