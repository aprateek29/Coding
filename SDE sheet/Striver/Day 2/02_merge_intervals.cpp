// leetcode

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end());
        
        vector<int> curr(2);
        
        curr[0] = intervals[0][0];     
        curr[1] = intervals[0][1];     
        
        bool flag = false;
        
        for (int i = 1; i < intervals.size(); i++) {
            if (curr[1] >= intervals[i][0]) {
                if (curr[1] < intervals[i][1]) {
                    curr[1] = intervals[i][1];
                } 
            } else {
                ans.push_back(curr);
                curr[0] = intervals[i][0];     
                curr[1] = intervals[i][1];
                if (i == intervals.size()-1) {
                    flag = true;
                }
            }
        }
        
        ans.push_back(curr);
        return ans;
        
    }
};