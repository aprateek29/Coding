#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool InList(int i, int j, string &str, vector<string> &s) {
    string curr = "";
    for (int k = i; k <= j; k++) {
        curr.push_back(str[k]);
    }

    for (auto i : s) {
        if (i == curr) 
            return true;
    }
    return false;
}

bool solve(string &str, vector<string> &s, int i, int j) {
    if ( i == str.size() && j == str.size()) {
        return true;
    }
    if (j == str.size()) return false;

    if (InList(i, j, str, s)) {
        return solve(str, s, j+1, j+1) || solve(str, s, i, j+1);
    }

    return solve(str, s, i, j+1);
}

int main() {

    vector<string> s;
    s.push_back("he");
    s.push_back("a");
    s.push_back("ab");
    s.push_back("ven");

    string str = "heaven";

    int i = 0;
    int j = 0;
    cout << solve(str, s, i, j);

    return 0;
}