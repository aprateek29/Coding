// Key Points
// It tells us about the dependency of one thing on another
// Like before DSA we should learn one programming language
// Before College we should go to school and learn basics.
// Do dfs
// Before return push the element into the stack

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void DFS(vector<int> adj[], int start, vector<bool> &vis, stack<int> &s) {
    vis[start] = true;
    for (auto node : adj[start]) {
        if (!vis[node]) {
            DFS(adj, node, vis, s);
        }
    }
    s.push(start);
}

int main() {

    int V = 6;
    vector<int> adj[V];

    adj[1].push_back(0);
    adj[1].push_back(3);

    adj[2].push_back(0);
    adj[2].push_back(4);

    adj[3].push_back(5);
    adj[4].push_back(5);

    int start = 0;
    vector<bool> vis(V, false);
    stack<int> s;

    for (int i = 0; i < V; i++) {
        if (!vis[i]) {
            DFS(adj,  i, vis, s);
        }
    }

    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }

    return 0;
}