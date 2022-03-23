#include <iostream>
#include <vector>
using namespace std;

bool dfs(vector<int> adj[], int start, vector<int> &vis, int cr) {
    vis[start] = cr;
    for (auto n : adj[start]) {
        if (vis[n] == -1) {
            if (dfs(adj, n, vis, 1-cr) == false) {
                return false;
            }
        } else if (vis[n] == cr) {
            cout << n << endl;
            return false;
        }
    }
    return true;
}

int main() {

    int v = 6;
    vector<int> adj[v];

    adj[0].push_back(1);
    adj[1].push_back(0);

    adj[1].push_back(2);
    adj[2].push_back(1);

    adj[2].push_back(3);
    adj[3].push_back(2);

    adj[3].push_back(4);
    adj[4].push_back(3);

    adj[3].push_back(5);
    adj[5].push_back(3);

    adj[1].push_back(5);
    adj[5].push_back(1);

    adj[1].push_back(4);
    adj[4].push_back(1);

    vector<int> vis(v, -1);
    int cr = 0;
    bool flag = true;

    for (int i = 0; i < v; i++) {
        if (vis[i] == -1) {
            if (!dfs(adj, i, vis, cr)) {
                flag = false;
            }
        }
    }

    cout << flag << endl;

    return 0;
}