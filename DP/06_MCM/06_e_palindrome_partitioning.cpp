#include <iostream>
#include <string>
#include <cstring>
#include <climits>
using namespace std;

int t[1001][1001];

bool isPalindrome(string String, int i, int j)
{
    while (i < j)
    {
        if (String[i] != String[j])
            return false;
        i++;
        j--;
    }
    return true;
}

int solve(string s, int i, int j) {
    if (i >= j) {
        return 0;
    }

    // do this before palindrome check
    if (t[i][j] != -1) {
        return t[i][j];
    }
    if (isPalindrome(s, i, j)) {
        return 0;
    }

    int ans = INT_MAX;
    for (int k = i; k < j; k++) {
        int temp = solve(s, i, k) + 1 + solve(s, k+1, j);
        ans = min(ans, temp);
    }
    return t[i][j] = ans;
}

int main() {

    string s = "arora";
    int n = s.size();
    memset(t, -1, sizeof(t));
    int i = 0;
    int j = n-1;
    cout << solve(s, i, j);


    return 0;
}