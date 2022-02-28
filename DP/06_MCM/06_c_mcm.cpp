// Matrix Chain Multiplication using Recursion
// Given a sequence of matrices, find the most efficient
// way to multiply these matrices together. The problem is
// not actually to  perform the multiplications, but merely
// to decide in which order to perform the multiplications.

#include <iostream>
#include <climits>
using namespace std;

int solve(int arr[], int i, int j)
{
    if (i >= j)
    {
        return 0;
    }
    int ans = INT_MAX;
    for (int k = i; k < j; k++)
    {
        int temp = solve(arr, i, k) + arr[i - 1] * arr[k] * arr[j] + solve(arr, k + 1, j);
        ans = min(temp, ans);
    }
    return ans;
}

int main()
{

    int arr[] = {40, 20, 30, 10, 30};
    int size = sizeof(arr) / sizeof(arr[0]);

    int i = 1;
    int j = size - 1;

    cout << solve(arr, i, j);

    return 0;
}