#include <iostream>
#include <stack>
#include <vector>
using namespace std;

void dfs(vector<int> adj[], int start, vector<bool> &vis, stack<int> &s) {
    vis[start] = true;
    for (auto n : adj[start])
        if (!vis[n])
            dfs(adj, n, vis, s);
    s.push(start);
}

int main() {

    int v = 6;
    vector<int> adj[v];

    adj[1].push_back(2);
    adj[1].push_back(3);

    adj[2].push_back(3);
    adj[2].push_back(4);

    adj[3].push_back(4);
    adj[3].push_back(5);

    vector<bool> vis(v, false);
    stack<int> s;

    for (int i = 1; i < v; i++) {
        if (!vis[i]) {
            dfs(adj, i, vis, s);
        }
    }

    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }

    return 0;
}