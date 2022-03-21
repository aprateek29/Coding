// leetcode

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxProfit = nums[0];
        int curr = nums[0] < 0 ? 0 : nums[0];
        
        for (int i = 1; i < nums.size(); i++) {
            curr += nums[i];
            maxProfit = maxProfit < curr ? curr : maxProfit;
            curr = curr < 0 ? 0 : curr;
            
        }
        return maxProfit;
    }
};