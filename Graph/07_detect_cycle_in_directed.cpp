#include <iostream>
#include <queue>
#include <vector>
using namespace std;

bool DFS(vector<int> adj[], int start, vector<bool> &vis, vector<bool> &ans) {
    vis[start] = true;
    ans[start] = true;

    for (auto node : adj[start]) {
        if (!vis[node]) {
            if (DFS(adj, node, vis, ans)) {
                return true;
            }
        } else if (ans[node] == true) {
            return true;
        }
    }
    ans[start] = false;
    return false;
}

int main() {

    int V = 6;
    vector<int> adj[V];

    adj[0].push_back(1);
    adj[1].push_back(2);
    adj[2].push_back(3);
    adj[2].push_back(0);
    adj[3].push_back(4);
    adj[3].push_back(5);
    adj[5].push_back(4);

    int start = 0;
    vector<bool> vis(V, false);
    vector<bool> ans(V, false);
    bool flag = false;

    for (int i = 0; i < V; i++) {
        if (!vis[i]) {
            if (DFS(adj, i, vis, ans)) {
                flag = true;
            }
        }
    }

    if (flag) {
        cout << "Has Cycle";
    } else {
        cout << "Don't have a cycle.";
    }

    return 0;
}