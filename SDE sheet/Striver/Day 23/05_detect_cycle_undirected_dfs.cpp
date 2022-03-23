#include <iostream>
#include <vector>
using namespace std;

bool dfs(vector<int> adj[], int start, int parent, vector<bool> &vis) {
    vis[start] = true;
    for (auto n : adj[start]) {
        if (!vis[n]) {
            if (dfs(adj, n, start, vis)) {
                return true;
            }
        } else if (n != parent) {
            return true;
        }

    }
    return false;
}

int main() {

    int v = 5;
    vector<int> adj[v];

    adj[0].push_back(1);
    adj[1].push_back(0);

    adj[1].push_back(2);
    adj[2].push_back(1);

    adj[2].push_back(3);
    adj[3].push_back(2);

    adj[3].push_back(4);
    adj[4].push_back(3);

    // adj[1].push_back(4);
    // adj[4].push_back(1);

    vector<bool> vis(v, false);
    bool flag = false;

    for (int i = 0; i < v; i++) {
        if (!vis[i]) {
            if (dfs(adj, i, -1, vis))
                flag = true;
        }
    }
    cout << flag << endl;


    return 0;
}