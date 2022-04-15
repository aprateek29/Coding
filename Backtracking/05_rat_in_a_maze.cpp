#include <iostream>
#include <string>
using namespace std;
#define r 3
#define c 3

void solve(int i, int j, int m[r][c], string &curr) {

    if (i < 0 || j < 0 || i >= r || j >= c || m[i][j] == 0) {
        return;
    } 

    if (i == r-1 && j == c-1) {
        cout << curr << endl;
    }

    int rowC[] = {0, 0, -1, 1};
    int colC[] = {1, -1, 0, 0};
    int cha[] = {'R', 'L', 'U', 'D'};

    for (int k = 0; k < 4; k++) {
        curr.push_back(cha[k]);
        m[i][j] = 0;
        solve(i+rowC[k], j+colC[k], m, curr);
        m[i][j] = 1;
        curr.pop_back();
    }
}

int main() {

    int m[r][c] = {
        {1, 1, 0},
        {1, 1, 1},
        {0, 0, 1},
    };

    string curr = "";
    solve(0, 0, m, curr);

    return 0;
}