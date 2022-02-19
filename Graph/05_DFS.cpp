// Key Points
// similar to dfs of tree
// we go in depth
// we visit a vertex and then call for its first neighbour recursivly
// then go to another neighbour
// Note - maintain a vis[] array to keep record which
// vertex has been visited

// Question - Print DFS of a graph

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

void DFS(vector<int> adj[], int start, vector<bool> &vis) {
    cout << start << " ";
    vis[start] = true;
    for (auto node : adj[start]) {
        if (vis[node] == false) {
            DFS(adj, node, vis);
        }
    }
}

int main() {

    int V = 6;
    vector<int> adj[V];

    adj[0].push_back(1);
    adj[0].push_back(5);

    adj[1].push_back(2);
    adj[1].push_back(4);

    adj[2].push_back(5);
    adj[3].push_back(5);

    adj[4].push_back(2);
    adj[4].push_back(3);

    adj[5].push_back(0);

    vector<bool> vis(V, false);
    int start = 0;
    DFS(adj, start, vis);

    return 0;
}