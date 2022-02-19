// Key Points - 
// replacing spaces with underscores to see results

// Question
// Given a string, return subsets with spaces;

#include <iostream>
#include <set>
#include <string>
using namespace std;

void solve(int pos, string s, int size, set<string> &sets, string &curr) {
    if (pos == size) {
        sets.insert(curr);
        return;
    }

    solve(pos+1, s, size, sets, curr);
    curr.push_back(s[pos]);
    curr.push_back('_');
    solve(pos+1, s, size, sets, curr);
    curr.pop_back();
    curr.pop_back();
}

int main() {

    string s = "abc";
    int size = s.size();
    int pos = 0;
    set<string> sets;
    string curr = "";
    solve(pos, s, size, sets, curr);

    for (auto str : sets) {
        cout << str << " ";
    }

    return 0;
}