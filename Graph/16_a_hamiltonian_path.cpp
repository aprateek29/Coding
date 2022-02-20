// Key Points
// From one starting vertex we have a path that covers all the vertex in the graph

#include<iostream>
#include<vector>
using namespace std;

bool solve(vector<int> adj[], int start, vector<bool> vis, int count) {
    vis[start] = true;
    count++;
    if (count == vis.size()) {
        return true;
    }

    for (auto n : adj[start]) {
        if (!vis[n]) {
            if (solve(adj, start, vis, count)) {
                return true;
            }
        }
    }
    vis[start] = false;
    return false;
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
    int count;

    for (int i = 0; i < V; i++) {
        count = 0;
        for (int j = 0; j < V; j++) {
            vis[j] = false;
        }

        if (solve(adj, i, vis, count)) {
            cout << true << endl;
        } else {
            cout << false << endl;
        }
    }

    return 0;
}