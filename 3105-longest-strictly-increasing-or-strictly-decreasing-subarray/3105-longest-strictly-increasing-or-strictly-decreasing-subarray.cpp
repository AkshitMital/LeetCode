class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size(), longest = 1, strictly_inc = 1, strictly_dec = 1;

        for(int i = 1; i < n; i++) {
            if(nums[i] > nums[i - 1]) strictly_inc += 1;
            else strictly_inc = 1;

            if(nums[i] < nums[i - 1]) strictly_dec += 1;
            else strictly_dec = 1;

            longest = max({longest, strictly_dec, strictly_inc});
        }

        return longest;
    }
};