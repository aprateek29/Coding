// Question is at last

#include <iostream>
using namespace std;

bool checkIfValid(int k, int arr[], int n, int mid) {
    int currCap = 1;
    int i = 0;
    int seen = 0;
    while (currCap != k) {
        if (seen+arr[i] > mid) {
            currCap++;
            seen = 0;
        }
        seen += arr[i];
        i++;
    }
    return (i == n);
}

int main() {

    int arr[] = {12, 34, 67, 90};
    int k = 2;
    int n = sizeof(arr) / sizeof(arr[0]);
    int sum = 0;
    int maxNum = 0;

    for (int i = 0; i < n; i++) {
        maxNum = max(maxNum, arr[i]);
        sum += arr[i];
    }

    int l = maxNum;
    int h = sum;
    int mid;
    int res = -1;
    while (l <= h) {
        mid = (l+h)/2;
        if (checkIfValid(k, arr, n, mid)) {
            res = mid;
            h = mid-1;
        } else {
            l = mid+1;
        }
    }

    cout << res;

    return 0;
}

// ALLOCATE MINIMUM NUMBER OF PAGES:

// Given number of pages in n different books and m students. The books are arranged in ascending order of number of pages. Every student is assigned to read some consecutive books. The task is to assign books in such a way that the maximum number of pages assigned to a student is minimum.

// Example :

// Input : pages[] = {12, 34, 67, 90}
//         m = 2
// Output : 113
// Explanation:
// There are 2 number of students. Books can be distributed 
// in following fashion : 
//   1) [12] and [34, 67, 90]
//       Max number of pages is allocated to student 
//       2 with 34 + 67 + 90 = 191 pages
//   2) [12, 34] and [67, 90]
//       Max number of pages is allocated to student
//       2 with 67 + 90 = 157 pages 
//   3) [12, 34, 67] and [90]
//       Max number of pages is allocated to student 
//       1 with 12 + 34 + 67 = 113 pages

// Of the 3 cases, Option 3 has the minimum pages = 113.
