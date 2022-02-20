// Key Points
// use recursion
// no visited array required

// Question - like MS paint change all consecutive array elements to new color

#include <iostream>
#include <vector>
using namespace std;

void solve(vector<vector<int>> &V, int i, int j, int newColor, int oldColor, int ROW, int COL) {
    if (i < 0 || i >= ROW || j < 0 || j >= COL || V[i][j] != oldColor) {
        return;
    }
    V[i][j] = newColor;
    solve(V, i, j-1, newColor, oldColor, ROW, COL); // left
    solve(V, i-1, j, newColor, oldColor, ROW, COL); // up
    solve(V, i+1, j, newColor, oldColor, ROW, COL); // down
    solve(V, i, j+1, newColor, oldColor, ROW, COL); // right
}

int main() {

    int ROW = 5;
    int COL = 5;

    int row1[] = {0, 1, 1, 1, 1};
    int row2[] = {4, 2, 4, 1, 5};
    int row3[] = {5, 6, 9, 4, 5};
    int row4[] = {7, 7, 7, 5, 5};
    int row5[] = {7, 8, 9, 12, 4};

    vector<int> v1(row1, row1+ROW);
    vector<int> v2(row2, row2+ROW);
    vector<int> v3(row3, row3+ROW);
    vector<int> v4(row4, row4+ROW);
    vector<int> v5(row5, row5+ROW);

    vector<vector<int>> V;
    V.push_back(v1);
    V.push_back(v2);
    V.push_back(v3);
    V.push_back(v4);
    V.push_back(v5);

    int newColor = 3;
    int oldColor = 7;
    

    solve(V, 4, 0, newColor, oldColor, ROW, COL);
    // for (int i = 0; i < ROW; i++) {
    //     for (int j = 0; j < COL; j++) {
    //         cout << V[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    return 0;
}