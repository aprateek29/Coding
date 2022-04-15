#include <iostream>
#include <string>
using namespace std;
#define r 4
#define c 3

void solve(int x, int y, char mat[r][c], int currIndex, string &currString, bool &flag)
{

    if (x < 0 || y < 0 || x >= r || y >= c || mat[x][y] != currString[currIndex])
    {
        return;
    }
    if (currIndex == currString.size()-1)
    {
        flag = true;
        return;
    }

    for (int i = -1; i <= 1; i++)
    {
        for (int j = -1; j <= 1; j++)
        {
            if (i == j && i == 0)
                continue;
            solve(x + i, y + j, mat, currIndex+1, currString, flag);
        }
    }
}

int main()
{

    char mat[r][c] = {
        {'B', 'C', 'A'},
        {'C', 'O', 'E'},
        {'H', 'E', 'T'},
        {'S', 'S', 'P'},
    };
    string s = "CHESS";
    bool flag = false;
    int currIndex;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            flag = false;
            currIndex = 0;
            if (s[0] == mat[i][j])
            {
                solve(i, j, mat, currIndex, s, flag);
                if (flag)
                {
                    cout << "Found" << endl;
                }
            }
        }
    }

    return 0;
}