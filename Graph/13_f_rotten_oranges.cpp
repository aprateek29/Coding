// Key Points

// Question - Rotten Oranges - 
// 0 - Wall
// 1 - Fresh Orange 
// 2 - Rotten Orange

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void push_neighbours(pair<int, int> p, vector<vector<int>> &V, queue<pair<int, int>> q, int ROW, int COL) {
    int X = p.first;
    int Y = p.second;
    int xDir[] = {-1, 1, 0, 0};
    int yDir[] = {0, 0, -1, 1};

    for (int i = 0; i < 4; i++) {
        if (X + xDir[i] < 0 || X + xDir[i] >= ROW || Y + yDir[i] < 0 || Y + yDir[i] >= COL || V[X + xDir[i]][Y + yDir[i]] != 1) {
            continue;
        }
        q.push({X + xDir[i], Y + yDir[i]});
        V[X + xDir[i]][Y + yDir[i]] = 2;
    }
}

int solve(vector<vector<int>> &V, int ROW, int COL) {

    int time = 0;
    queue<pair<int, int>> q;

    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            if (V[i][j] == 2 ) {
                q.push({i, j});
            }
        }
    }

    int count = q.size();

    while (count > 0) {
        for (int i = 0; i < count; i++) {
            pair<int, int> p = q.front();
            q.pop();
            push_neighbours(p, V, q, ROW, COL);
        }
        count = q.size();
        if (count > 0) {
            time++;
        }
    }
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            if (V[i][j] == 1) {
                return -1;
            }
        }
    }
    return time;
}

int main() {

    int ROW = 4;
    int COL = 4;

    int row1[] = {0,0,0,1};
    int row2[] = {2,1,1,1};
    int row3[] = {2,0,2,0};
    int row4[] = {1,1,0,2};

    vector<int> v1(row1, row1+COL);
    vector<int> v2(row2, row2+COL);
    vector<int> v3(row3, row3+COL);
    vector<int> v4(row4, row4+COL);

    vector<vector<int>> V;

    V.push_back(v1);
    V.push_back(v2);
    V.push_back(v3);
    V.push_back(v4);

    cout << solve(V, ROW, COL);

    return 0;
}