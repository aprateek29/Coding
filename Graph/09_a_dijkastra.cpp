// Key Points
// Single Source Shortest Path
// use proc[] and dis[]
// two loops
// getMinUnprocessedEdge
// update dis[v] if dis[v] > dis[u] + g[u][v]

// Condition - There should be no negative edges

// Time Complexity - O(V*V)
// Space Complexity - O(V*V) + O(V) + O(V)

#include <iostream>
#include <vector>
#include <climits>
#define V 5
using namespace std;

int getMinUnprocessedVertex(vector<bool> &proc, vector<int> &dis)
{
    int minIndex = -1;
    int minVal = INT_MAX;

    for (int i = 0; i < V; i++)
    {
        if (proc[i] == false && dis[i] < minVal)
        {
            minVal = dis[i];
            minIndex = i;
        }
    }
    return minIndex;
}

void dijkastra(int g[V][V], int start)
{
    vector<bool> proc(V, false);
    vector<int> dis(V, INT_MAX);

    dis[start] = 0;

    for (int i = 0; i < V; i++)
    {
        int u = getMinUnprocessedVertex(proc, dis);
        proc[u] = true;
        for (int v = 0; v < V; v++)
        {
            if (g[u][v] && (dis[u] + g[u][v] < dis[v]))
            {
                dis[v] = dis[u] + g[u][v];
            }
        }
    }

    for (auto i : dis)
    {
        cout << i << " ";
    }
}

int main()
{

    int g[V][V];
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            g[i][j] = 0;
        }
    }

    g[0][1] = 1;
    g[0][2] = 4;

    g[1][2] = 2;
    g[1][3] = 4;

    g[2][4] = 4;
    g[3][4] = 4;

    int start = 0;
    dijkastra(g, start);

    return 0;
}