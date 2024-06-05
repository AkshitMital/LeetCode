class Solution {
private:
    int solve(vector<int>& nums, int index, vector<int>& dp){
        if(index == 0) return nums[index];
        if(index < 0) return 0;
        if(dp[index] != -1) return dp[index];
        int pick = nums[index] + solve(nums, index - 2, dp);
        int not_pick = 0 + solve(nums, index - 1, dp);

        return dp[index] = max(pick, not_pick);
    }
public:
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        return solve(nums, nums.size()-1, dp);
    }
};