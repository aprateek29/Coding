#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Job {
    int id;     
    int dead;   
    int profit; 
};

bool comp(pair<int, int> p1, pair<int, int> p2) {
    if (p1.first < p2.first) return true;
    if (p1.second > p2.second) return true;
    return false;
}

void solve(Job arr[], int n) {
    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++) {
        v.push_back({arr[i].dead, arr[i].profit});
    }

    sort(v.begin(), v.end(), comp);
    
    int curr = 1;
    int currProfit = v[0].second;
    int currDead = v[0].first;

    for (int i = 1; i < n; i++) {
        if (currDead < v[i].first) {
            curr++;
            currProfit += v[i].second;
        }
    }

    cout << curr << " " << currProfit;
}

int main() {
    
    int n = 4;
    Job arr[4];

    arr[0].id = 1;
    arr[0].dead = 4;
    arr[0].profit = 20;

    arr[1].id = 2;
    arr[1].dead = 1;
    arr[1].profit = 10;

    arr[2].id = 3;
    arr[2].dead = 1;
    arr[2].profit = 40;

    arr[3].id = 4;
    arr[3].dead = 1;
    arr[3].profit = 30;

    solve(arr, n);

    return 0;
}