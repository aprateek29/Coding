// Key Points
// TC - O(n!)

// Question
// Find all the permutation of give string
// eg - "abc"

#include <iostream>
#include <set>
#include <string>
using namespace std;

void solve(int pos, string &s, int size, set<string> &sets) {
    if (pos == size-1) {
        sets.insert(s);
    } else {
        for (int i = pos; i < size; i++) {
            swap(s[pos], s[i]);
            solve(pos+1, s, size, sets);
            swap(s[pos], s[i]);
        }
    }
}

int main() {
    string s = "abc";
    int size = s.size();
    set<string> sets;
    int pos = 0;
    solve(pos, s, size, sets);

    for (auto str : sets) {
        cout << str << " ";
    }

    return 0;
}