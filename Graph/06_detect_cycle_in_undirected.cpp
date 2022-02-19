// Key Points
// Do a DFS and if a visited node is encounted then
// check if that node is the parent.
// if not parent then there is a cycle.
// Note - maintain a vis[] array to keep record which
// vertex has been visited

// Question - Detect cycle in a undirected graph

#include <iostream>
#include <vector>
using namespace std;

bool DFS(vector<int> adj[], int start, int parent, vector<bool> &vis) {
    vis[start] = true;
    for (auto node : adj[start]) {
        if (!vis[node]) {
            if (DFS(adj, node, start, vis)) {
                return true;
            }
        } else if(node != parent) {
            return true;
        }
    }
    return false;
}

int main() {

    int V = 9;
    vector<int> adj[V];

    adj[0].push_back(4);
    adj[4].push_back(5);
    adj[5].push_back(6);

    adj[1].push_back(2);
    adj[2].push_back(3);
    adj[3].push_back(8);

    int start = 0;
    int parent = -1;
    vector<bool> vis(V, false);
    bool flag = false;
    for (int i = 0; i < V; i++) {
        if (!vis[i]) {
            if (DFS(adj, i, parent, vis)) {
                flag = true;
            }
        }
    }

    if (flag) {
        cout << "Has Cycle";
    } else {
        cout << "Don't have a cycle";
    }

    return 0;
}