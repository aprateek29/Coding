// 0 1 1 0 0
// 1 0 0 1 0
// 0 0 1 0 0
// 1 0 0 0 1

#include <iostream>
using namespace std;
#define r 4
#define c 4

bool isSafe(int i, int j) {
    if (i < 0 || j < 0 || i >= r || j >= c) {
        return false;
    }
    return true;
}

void solve(int grid[r][c], int x, int y, bool vis[r][c]) {
    vis[x][y] = true;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (!vis[x+i][y+j] && isSafe(x+i, y+j)) {
                solve(grid, x+i, y+j, vis);
            }
        }
    }
}

int main() {

    int grid[r][c] = {
        {1, 0, 0, 1},
        {0, 1, 1, 0},
        {0, 1, 1, 0},
        {1, 0, 0, 1},
    };

    bool vis[r][c];
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (grid[i][j] == 1) {
                vis[i][j] = 0;
            } else {
                vis[i][j] = 1;
            }
        }
    }

    int count = 0;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (vis[i][j] == 0) {
                solve(grid, i, j, vis);
                count++;
            }
        }
    }
    cout << count << endl;

    return 0;
}