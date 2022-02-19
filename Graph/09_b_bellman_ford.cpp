// Key Points
// Single Source Shortest Path
// Can work even with negative edges
// use two loops
// use edge list
// update dis[v] when dis[v]

// Time complexity - O(VE)

// can also be used to find negative cycles

// Question - Find single source shortest path

#include <iostream>
#include <vector>
#include <climits>
#define V 5
using namespace std;

void bellmanFord(int g[V][V], int start) {
    vector<pair<int, int>> edgeList;
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (g[i][j] != 0) {
                edgeList.push_back({i, j});
            }
        }
    }

    vector<int> dis(V, INT_MAX);
    dis[start] = 0;
    for (int i = 0; i < V-1; i++) {
        for (int j = 0; j < V; j++) {
            int u = edgeList[j].first;
            int v = edgeList[j].second;
            if (g[u][v] && dis[v] > dis[u] + g[u][v]) {
                dis[v] = dis[u] + g[u][v];
            }
        }
    }

    for (auto i : dis) {
        cout << i << " ";
    }
}

int main() {

    int g[V][V];
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            g[i][j] = 0;
        }
    }

    g[0][1] = 5;
    g[0][2] = 3;

    g[2][1] = -2;
    g[2][3] = 1;

    g[1][4] = 4;
    g[3][4] = 4;

    int start = 0;
    bellmanFord(g, start);    

    return 0;
}