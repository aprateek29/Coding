#include <iostream>
#include <string>
using namespace std;

int main() {
    string s = "abcdefgh";
    int x = s.find("abz");
    cout << x << " " <<int(s.npos);
    return 0;
}