#include <iostream>
#include <string>
#include <vector>
#define N 3
#define M 3
using namespace std;

bool isSafe(int row, int col, int maze[N][M]) {
    if (maze[row][col] == 0) {
        return false;
    }
    if (row < 0 || row > N || col < 0 || col > M) {
        return false;
    }
    return true;
}

void solve(int row, int col, vector<string> &paths, string currStr, int maze[N][M]) {
    if (row == N-1 && col == M - 1) {
        paths.push_back(currStr);
        return;
    }

    int row_change[] = {0, -1, 0, 1};
    int col_change[] = {-1, 0, 1, 0};
    char dic[] = {'L', 'U', 'R', 'D'};
    for (int i = 0; i < 4; i++) {
        if (isSafe(row+row_change[i], col+col_change[i], maze)) {
            maze[row][col] = 0;
            currStr.push_back(dic[i]);
            solve(row+row_change[i], col +col_change[i], paths, currStr, maze);
            maze[row][col] = 1;
            currStr.pop_back();
        }
    }
}

int main() {
    int n = N;
    int m = M;
    int maze[N][M] = {
        {1, 1, 0},
        {1, 1, 1},
        {0, 0, 1},
    };
    vector<string> paths;
    string currStr = "";
    int row = 0, col = 0;
    solve(row, col, paths, currStr, maze);

    for (auto str : paths) {
        cout << str << endl;
    }

    return 0;
}