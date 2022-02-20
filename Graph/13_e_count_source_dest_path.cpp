#include <iostream>
#include <vector>
using namespace std;

void solve(vector<int> adj[], int start, int dest, vector<bool> &vis, int &count) {
    vis[start] = true;
    if (start == dest) {
        count ++;
    }
    for (auto node : adj[start]){
        if (!vis[node]) {
            solve(adj, node, dest, vis, count);
        }
    }
    vis[start] = false;
}

int main() {

    int V = 5;
    vector<int> adj[V];

    adj[0].push_back(1);
    adj[0].push_back(2);
    adj[0].push_back(3);

    adj[1].push_back(2);

    adj[2].push_back(3);

    vector<bool> vis(V, false);
    int count = 0;
    int start = 0;
    int dest = 3;
    solve(adj, start, dest, vis, count);
    cout << count << endl;
    return 0;
}