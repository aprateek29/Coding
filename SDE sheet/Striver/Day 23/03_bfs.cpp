#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main()
{

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
    queue<int> q;
    q.push(start);
    vis[start] = true;

    while (!q.empty()) {
        int s = q.front();
        q.pop();
        cout << s << " ";

        for (auto n : adj[s]) {
            if (!vis[n]) {
                q.push(n);
                vis[n] = true;
            }
        }
    }

    return 0;
}