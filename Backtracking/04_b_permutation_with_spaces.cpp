// Key points
// replacing spaces with underscores for better understanding

// Question
// print all permutation of a string with spaces

#include <iostream>
#include <set>
#include <string>
using namespace std;

void solve(int pos, string s, int n, string &op, set<string> &strings) {
    if (pos == n-1) {
        cout << op << endl;
        return;
    } 
    op.push_back(s[pos]);
    solve(pos+1, s, n, op, strings);
    op.push_back('_');
    solve(pos+1, s, n, op, strings);
    op.pop_back();
}

int main() {

    int pos = 0;
    string s= "abc";
    int n = s.size();
    set<string> strings;
    string curr = "";
    solve(pos, s, n, curr, strings);

    for (auto str : strings) {
        cout << str << " ";
    }

    return 0;
}