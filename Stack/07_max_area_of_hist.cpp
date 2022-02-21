#include <iostream>
#include <vector>
#include <stack>
#include <climits>
using namespace std;

vector<int> NGL(int arr[], int n) {
    stack<pair<int, int>> s; // ele, ind
    vector<int> res(n);
    for (int i = 0; i < n; i++) {
        while (!s.empty() && arr[i] <= s.top().first) {
            s.pop();
        }
        if (s.size() == 0) {
            res[i] = -1;
        } else {
            res[i] = s.top().second;
        }
        s.push({arr[i], i});
    }
    return res;
}

vector<int> NGR(int arr[], int n) {
    stack<pair<int, int>> s; // ele, ind
    vector<int> ans(n);
    for (int i = n-1; i > -1; i--) {
        while(!s.empty() && arr[i] <= s.top().first) {
            s.pop();
        }
        if (s.size() == 0) {
            ans[i] = n;
        } else {
            ans[i] = s.top().second;
        }

        s.push({arr[i], i});
    }
    return ans;
}

int main() {

    int arr[] = {6, 2, 5, 4, 5, 1, 6};
    int n = 7;

    vector<int> ngl = NGL(arr, n);
    vector<int> ngr = NGR(arr, n);
    int width = 0;
    int max = INT_MIN;
    for (int i = 0; i < n; i++) {
        width = ngr[i] - ngl[i] - 1;
        if (width * arr[i] > max) {
            max = width * arr[i];
        }
    }
    cout << max << endl;

    return 0;
}