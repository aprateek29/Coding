// Key Points
// Graph which can be divided into two parts such that no vertex of a set is connected to another node 
// in same set

#include <iostream>
#include <vector>
using namespace std;

bool dfs(int start, vector<int> adj[], vector<int> col, int cr) {
    col[start] = cr;
    for (auto n : adj[start]) {
        if (col[n] == -1) {
            if (dfs(n, adj, col, 1-cr)) {
                return true;
            }
        } else {
            if (col[start] != col[n]) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    int V = 3;
    // int V = 6;
    vector<int> adj[V];
    adj[0].push_back(1);
    adj[1].push_back(2);
    adj[2].push_back(0);

    // adj[0].push_back(1);
    // adj[0].push_back(5);

    // adj[1].push_back(2);
    // adj[1].push_back(4);

    // adj[2].push_back(5);
    // adj[3].push_back(5);

    // adj[4].push_back(2);
    // adj[4].push_back(3);

    // adj[5].push_back(0);

    vector<int> col(V, -1);
    int start = 0;
    int cr = 0;
    cout << dfs(start, adj, col, cr);
    return 0;
}