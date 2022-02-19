// Key Points 
// similar to bfs of tree
// we go level by level or layer by layer
// Use a queue push the neighbours
// then for each neighbour call bfs one by one
// Note - maintain a vis[] array to keep record which
// vertex has been visited

// Question - Print BFS of a graph

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void BFS(vector<int> adj[], int start, int V) {

    vector<bool> vis(V, false);
    queue<int> q;
    q.push(start);
    vis[start] = true;
    while (!q.empty()) {
        int node = q.front();
        cout << node << " ";
        q.pop();

        for (auto i : adj[node]) {
            if (vis[i] == false) {
                q.push(i);
                vis[i] = true;
            }
        }
    }
}

int main() {

    int V = 7;
    vector<int> adj[V];

    adj[0].push_back(1);
    adj[0].push_back(2);
    adj[0].push_back(3);
    adj[0].push_back(4);

    adj[1].push_back(2);
    adj[1].push_back(5);

    adj[2].push_back(6);
    adj[3].push_back(6);

    adj[4].push_back(5);

    int start = 0;
    BFS(adj, start, V);

    return 0;
}