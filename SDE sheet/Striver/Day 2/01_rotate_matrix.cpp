// leetcode

class Solution {
public:
    void rotate(vector<vector<int>>& arr) {
        int row = arr.size();
        int col = arr[0].size();
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < i; j++) {
                swap(arr[i][j], arr[j][i]);
            }
        }

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col/2; j++) {
                swap(arr[i][j], arr[i][col-j-1]);
            }
        }
    }
};