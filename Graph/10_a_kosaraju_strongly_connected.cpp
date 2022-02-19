// Key Points
// Used to find the strongly connected components

#include <iostream>
#include <vector>
#include <stack>
#define V 10
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

void DFSTwo(vector<int> adj[], int start, vector<bool> &vis) {
    // cout << start << " ";
    vis[start] = true;
    for (auto node : adj[start]) {
        if (!vis[node]) {
            DFSTwo(adj, node, vis);
        }
    }
}

int main() {

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

    int start = 0;
    vector<bool> vis(V, false);
    stack<int> s;
    for (int i = 0; i < V; i++) {
        if (!vis[i]) {
            DFS(adj, start, vis, s);
        }
    }

    for (int i = 0; i < V; i++) {
        vis[i] = false;
    }

    vector<int> adjTwo[V];

    for (int i = 0; i < V; i++) {
        for (int j = 0; j < adj[i].size(); j++) {
            cout << j << " ";
        }
        cout << endl;
    }

    // for (int i = 0; i < V; i++) {
    //     for (auto node : adjTwo[i]) {
    //         cout << node << " ";
    //     }
    //     cout << endl;
    // }


    // while (!s.empty()) {
    //     if (!vis[s.top()]) {
    //         DFSTwo(adjTwo, s.top(), vis);
    //         s.pop();
    //         cout << endl;
    //     }
    // }

    return 0;
}