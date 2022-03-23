#include <iostream>
#include <vector>
using namespace std;

bool dfs(vector<int> adj[], int start, vector<bool> &vis, vector<bool> &anc) {
    vis[start] = true;
    anc[start] = true;

    for (auto n : adj[start]) {
        if (!vis[n]) {
            if (dfs(adj, n, vis, anc)) {
                return true;
            }
        } else if (anc[n]) {
            return true;
        }
    }
    anc[start] = false;
    return false;
}

int main() {

    int v = 6;
    vector<int> adj[v];

    adj[0].push_back(1);
    
    // adj[1].push_back(2);
    adj[1].push_back(5);

    adj[2].push_back(3);

    adj[3].push_back(4);

    adj[4].push_back(1);
    adj[4].push_back(0);

    vector<bool> vis(v, false);
    vector<bool> anc(v, false);

    bool flag = false;

    for (int i = 0; i < v; i++) {
        if (!vis[i]) {
            if (dfs(adj, i, vis, anc)) {
                flag = true;
            }
        }
    }
    cout << flag << endl;

    return 0;
}