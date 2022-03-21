// leetcode 

class Solution {
public:
    vector<vector<int>> generate(int n) {
        
        vector<vector<int>> result;
        for (int i = 1; i <= n; i++) {
            vector<int> v;
            for (int j = 0; j < i; j++) {
                if (j == 0 || j == i-1) {
                    v.push_back(1);
                } else {
                    v.push_back(result[i-2][j-1] + result[i-2][j]);
                }
            }
            result.push_back(v);
        }
    return result;
    }
};