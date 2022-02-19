#include <iostream>
#include <vector>
using namespace std;

void DFS(vector<int> adj[], int start, vector<bool> &vis) {
    vis[start] = true;
    for (auto node : adj[start]) {
        if (!vis[node]) {
            DFS(adj, node, vis);
        }
    }
}

int main() {

    int V = 5;
    vector<int> adj[V];

    adj[0].push_back(1);
    adj[0].push_back(3);

    adj[1].push_back(2);

    adj[3].push_back(4);

    vector<bool> vis(V, false);
    int last = -1;

    for (int i = 0; i < V; i++) {
        if (!vis[i]) {
            DFS(adj, i, vis);
            last = i;
        }
    }

    cout << last << endl;
    

    return 0;
}