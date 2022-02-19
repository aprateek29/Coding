// Key Points
// use 2d Vis array
// valid function for cords inside boudaries

// Question - Find the number of islands.
// Given an 2d matrix find number of islands.
// land is indicated by 1 and water by 0
// connected 1's (all directions including diagonals) are one single island

#include <iostream>
#define V 5
using namespace std;

bool valid(int x, int y, int row, int col, bool vis[V][V]) {
    if (x >= 0 && y >= 0 && x < row && y < col && vis[x][y] == false) {
        return true;
    }
    return false;
}

void DFS(int g[V][V], int X, int Y, bool vis[V][V]) {

    vis[X][Y] = true;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (i == 0 && j == 0) {
                continue;
            }

            if (valid(X+i, Y+j, V, V, vis)) {
                DFS(g, X+i, Y+j, vis); 
            }
        }
    }

}

int main() {

    int g[V][V];

    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            g[i][j] = 0;
        }
    }

    g[0][0] = 1;
    g[0][1] = 1;

    g[1][2] = 1;
    g[1][3] = 1;

    g[2][2] = 1;

    g[4][1] = 1;
    g[4][2] = 1;

    bool vis[V][V];

    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (g[i][j] == 0) {
                vis[i][j] = true;
            } else {
                vis[i][j] = false;
            }
        }
    }

    int count = 0;
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (!vis[i][j]) {
                DFS(g, i, j, vis);
                count++;
            }
        }
    }
    cout << count << endl;

    return 0;
}