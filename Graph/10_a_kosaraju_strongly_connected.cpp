// Key Points
// Used to find the strongly connected components
// STEP1 - do dfsWithStack
// STEP2 - reverse the link of the graph
// STEP3 - do dfs

#include <iostream>
#include <stack>
#include <vector>
#include <climits>
using namespace std;

void dfsWithStack(vector<int> adj[], int start, vector<bool> &vis, stack<int> &stk) {
    vis[start] = true;
    for (auto n : adj[start])
        if (!vis[n])
            dfsWithStack(adj, n, vis, stk);
    stk.push(start);
}

void dfs(vector<int> newAdj[], int start, vector<bool> &vis) {
    cout << start << " ";
    vis[start] = true;
    for (auto n : newAdj[start])
        if (!vis[n])
            dfs(newAdj, n, vis);
}


int main() {

    int V = 10;
    vector<int> adj[V];

    adj[0].push_back(1);
    adj[1].push_back(2);
    adj[2].push_back(0);

    adj[2].push_back(3);

    adj[3].push_back(4);
    adj[4].push_back(3);

    adj[5].push_back(4);

    adj[5].push_back(6);
    adj[6].push_back(7);
    adj[7].push_back(8);
    adj[8].push_back(5);

    adj[6].push_back(9);
    stack<int> stk;

    vector<bool> vis(V, false);
    for (int i = 0; i < V; i++) {
        if (!vis[i]) {
            dfsWithStack(adj, i, vis, stk);
        }
    }

    for (int i = 0; i < V; i++) {
        vis[i] = false;
    }
    vector<int> newAdj[V];

    for (int i = 0; i < V; i++) {
        for (int j = 0; j < adj[i].size(); j++) {
            newAdj[adj[i][j]].push_back(i);
        }
    }

    while (!stk.empty()) {
        int t = stk.top();
        stk.pop();
        if (!vis[t]) {
            dfs(newAdj, t, vis);
            cout << endl;
        }
    }

    
    return 0;
}