#include <iostream>
#include <climits>
#include <cstring>
using namespace std;


int t[1001][1001];

int solve(int arr[], int i, int j)
{
    if (i >= j)
    {
        return 0;
    }
    if (t[i][j] != -1) {
        return t[i][j];
    }
    int ans = INT_MAX;
    for (int k = i; k < j; k++)
    {
        int temp = solve(arr, i, k) + arr[i - 1] * arr[k] * arr[j] + solve(arr, k + 1, j);
        ans = min(temp, ans);
    }
    return t[i][j] = ans;
}

int main()
{

    int arr[] = {40, 20, 30, 10, 30};
    int size = sizeof(arr) / sizeof(arr[0]);

    int i = 1;
    int j = size - 1;

    memset(t, -1, sizeof(t));

    cout << solve(arr, i, j);

    return 0;
}