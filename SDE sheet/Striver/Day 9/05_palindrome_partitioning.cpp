// Problem Statement: You are given a string s, partition it in 
// such a way that every substring is a palindrome. 
// Return all such palindromic partitions of s.

#include <iostream>
#include <string>
#include <set>
#include <vector>
using namespace std;

bool isPalindrom(string s) {
    int i = 0;
    int j = s.size()-1;
    while (i < j) {
        if (s[i] != s[j]) {
            return false;
        }
        i++;
        j--;
    }
    return true;
}

void solve(string s, int n, string curr, set<string> &res) {
    if (n==0) {
        if (isPalindrom(curr)) {
            res.insert(curr);
        }
        return;
    }
    solve(s, n-1, curr, res);
    curr += s[n-1];
    solve(s, n-1, curr, res);
}

int main() {

    string s = "aab";
    int n = s.size();

    set<string> res;
    string curr = "";
    solve(s, n, curr, res);

    for (auto str : res) {
        cout << str << " ";
    }

    return 0;
}