// Key points
// replacing spaces with underscores for better understanding

// Question
// print all permutation of a string with spaces

#include <iostream>
#include <set>
#include <string>
using namespace std;

void solve(int pos, string s, int n, set<string> &strings) {
    if (pos == n-1) {
        strings.insert(s);
        return;
    } 
    solve(pos+1, s, n, strings);
    s.insert(pos+1, "_");
    solve(pos+2, s, n+1, strings);
    s.erase(pos+1, 1);
}

int main() {

    int pos = 0;
    string s= "abc";
    int n = s.size();
    set<string> strings;
    string curr = "";
    solve(pos, s, n, strings);

    for (auto str : strings) {
        cout << str << " ";
    }

    return 0;
}