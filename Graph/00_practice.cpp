#include <iostream>
#include <vector>
using namespace std;


bool valid(int x, int y, int row, int col, vector<vector<bool>> &vis) {
    if (x >= 0 && y >= 0 && x < row && y < col && vis[x][y] == false) {
        return true;
    }
    return false;
}

void dfs(vector<vector<int>> &g, int row, int col, vector<vector<bool>> &vis) {
    vis[row][col] = true;

    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (i == 0 && j == 0) {
                continue;
            }
            if (valid(row+i, col+j, 5, 5, vis)) {
                dfs(g, row+i, col+j, vis);
            }
        }
    }
}

void solve(vector<vector<int>> &g, int row, int col) {
    vector<bool> V(row, true);
    vector<vector<bool>> vis(row, V);

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (g[i][j] == 1) {
                vis[i][j] = false;
            }
        }
    }
    int count = 0;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (!vis[i][j]) {
                dfs(g, i, j, vis);
                count++;
            }
        }
    }
    cout << count << endl;
}

int main() {

    int size = 5;
    int row1[] = {1,1,0,0,0};
    int row2[] = {0,0,1,1,0};
    int row3[] = {0,0,1,0,0};
    int row4[] = {0,0,0,0,0};
    int row5[] = {0,1,1,0,0};

    vector<int> v1(row1, row1 + size);
    vector<int> v2(row2, row2 + size);
    vector<int> v3(row3, row3 + size);
    vector<int> v4(row4, row4 + size);
    vector<int> v5(row5, row5 + size);

    vector<vector<int>> graph;
    graph.push_back(v1);
    graph.push_back(v2);
    graph.push_back(v3);
    graph.push_back(v4);
    graph.push_back(v5);


    solve(graph, size, size);

    return 0;
}