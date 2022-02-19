// Key Points
// We can use dijkastra for every vertex but it has a time complexity of V*V
// After using priority_queue or set it becomes E*logV 
// Still high for all pairs = V * ElogV

// We can use Bellman ford but it's time complexity is EV
// so for all pairs V *EV

// Hence we use Flloyd Warshell
// It's TC is O(V*V*V)

// Question - All Pair shortest path
// finding the shortest distance between every pair of vertices in the graph


#include <iostream>
#include <vector>
#include <climits>
#define V 4
using namespace std;

void flloyd(int g[V][V]) {
    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (g[i][k] != INT_MAX && g[k][j] != INT_MAX && g[i][k] + g[k][j] < g[i][j]) {
                    g[i][j] = g[i][k] + g[k][j];
                }
            }
        }
    }

    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            cout << g[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {

    int g[V][V];
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            g[i][j] = INT_MAX;
            if (i == j) {
                g[i][j] = 0;
            }
        }
    }

    g[0][1] = 13;
    g[0][2] = 2;

    g[2][1] = 10;
    g[2][3] = 4;
    g[1][3] = 6;

    flloyd(g);

    return 0;
}