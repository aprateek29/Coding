// leetcode

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        
        int size = nums.size();
        
        int i = size-2;
        while (i >= 0 && nums[i+1] <= nums[i]) {
            i--;
        }
        
        if (i == -1) {
            reverse(nums.begin(), nums.end());
        } else {
            int l = size-1;
            while (nums[i] >= nums[l]) {
                l--;
            }
            swap(nums[i], nums[l]);
            reverse(nums.begin()+i+1, nums.end());
        }
    }
};