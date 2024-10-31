class Solution {
private:
    bool solve(int ind, int target, vector<int>& nums, vector<vector<int>>& dp){
        if(target == 0) return true;
        if(ind == 0) return (nums[0] == target);
        if(dp[ind][target] != -1) return dp[ind][target];
        bool exclude = solve(ind-1, target, nums, dp);
        bool include = false;
        if(target >= nums[ind]) include = solve(ind-1, target-nums[ind], nums, dp);

        return dp[ind][target] = include | exclude;
    }
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0, n = nums.size();
        for(auto num : nums) sum += num;
        if(sum % 2 != 0) return false;
        vector<vector<int>> dp(n, vector<int>((sum/2)+1, -1));
        return solve(n-1, sum/2, nums, dp);
    }
};