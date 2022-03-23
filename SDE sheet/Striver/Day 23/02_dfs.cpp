#include <iostream>
#include <vector>
using namespace std;

void dfs(vector<int> adj[], int start, bool vis[]) {
    cout << start << " ";
    vis[start] = true;
    for (auto n : adj[start])
        if (!vis[n])
            dfs(adj, n, vis);
}

int main() {

    int v = 6;
    vector<int> adj[v];
    adj[1].push_back(2);
    adj[1].push_back(3);
    adj[1].push_back(4);
    adj[1].push_back(5);

    adj[2].push_back(1);
    adj[2].push_back(4);

    adj[3].push_back(1);

    adj[4].push_back(1);
    adj[4].push_back(2);

    adj[5].push_back(1);

    int start = 2;
    bool vis[v] = {0};

    dfs(adj, start, vis);

    return 0;
}