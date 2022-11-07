#include <iostream>
#include <string>
using namespace std;

void reverse(string &s, int i, int j) {
    while (i <= j) {
        swap(s[i], s[j]);
        i++;
        j--;
    }
}

int main() {

    string s = "this is an amazing program";
    int n = s.size();
    int i = n-1;
    int j = n-1;

    for (int k = n-1; k >= -1; k++) {
        if (s[k] == ' ' || k == -1) {
            j = k+1;
            reverse(s, i, j);
            i = k;
        }
    }

    for (auto i : s) {
        cout << i;
    }

    return 0;
}