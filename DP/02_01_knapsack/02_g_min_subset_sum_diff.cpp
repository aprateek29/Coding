// Sum of subset differences
// Given a set of integers, the task is to divide it into two sets 
// S1 and S2 such that the absolute difference between their sums is minimum.
// If there is a set S with n elements, then if we assume Subset1 has m elements, 
// Subset2 must have n-m elements and the value of abs(sum(Subset1) - sum(Subset2)) 
// should be minimum.

// Example:
// Input:  arr[] = {1, 6, 11, 5} 
// Output: 1
// Explanation:
// Subset1 = {1, 5, 6}, sum of Subset1 = 12 
// Subset2 = {11}, sum of Subset2 = 11
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int solve(int arr[], int sum, int n) {
    bool t[n+1][sum+1];

    for (int i = 0; i < n+1; i++) {
        for (int j = 0; j < sum+1; j++) {
            if (i==0) {
                t[i][j] = 0;
            }
            if (j==0) {
                t[i][j] = 1;
            }
        }
    }

    for (int i = 1; i < n+1; i++) {
        for (int j = 1; j < sum+1; j++) {
            if (arr[i-1] > j) {
                t[i][j] = t[i-1][j];
            } else {
                t[i][j] = t[i-1][j] || t[i-1][j-arr[i-1]];
            }
        }
    }

    //  if no negative numbers in given array
    // int ans = -1;
    // for (int i = 0; i < n+1; i++) {
    //     for (int j = 0; j < (sum+1)/2; j++) {
    //         if (t[i][j] == 1) {
    //             ans = j;
    //         }
    //     }
    // }

    // return (sum-ans) - ans;

    vector<int> ans;
    for (int i = n; i < n+1; i++) {
        for (int j = 0; j <= (sum+1)/2; j++) {
            if (t[i][j] == 1) 
            ans.push_back(j);
        }
    }
    for (auto i : ans) {
        cout << i << " ";
    }
    int minE = INT_MAX;
    for (auto i : ans) {
        minE = min(minE, sum-2*i);
    }
    return abs(minE);
}

int main() {

    int arr[] = {1, 6, 11, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }

    cout << solve(arr, sum, n);

    return 0;
}











