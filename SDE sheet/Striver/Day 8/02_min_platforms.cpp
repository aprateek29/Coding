#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solve(int arr[], int dep[], int n) {
    sort(arr, arr+n);
    sort(dep, dep+n);

    int curr = 1;
    int max = 0;

    int j = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] < dep[j]) {
            
        } else {
            while (arr[i] >= dep[j])
                j++;
            curr++;
        }
        max = max > curr ? max : curr;
    cout << curr << " ";
    }
}

int main() {
    int arr[]={900,945,955,1100,1500,1800};
    int dep[]={920,1200,1130,1150,1900,2000};
    int n=sizeof(dep)/sizeof(dep[0]);

    solve(arr, dep, n);

    return 0;
}