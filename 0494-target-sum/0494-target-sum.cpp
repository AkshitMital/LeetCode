class Solution {
private:
    int solve(int ind, vector<int>& nums, int target, vector<vector<int>>& dp){
        if(ind == 0){
            if(nums[0] == 0 && target == 0) return 2;
            if(nums[0] == target || target == 0) return 1;
            return 0;
        }
        if(dp[ind][target] != -1) return dp[ind][target];
        int not_pick = solve(ind-1, nums, target, dp);
        int pick = 0;
        if(nums[ind] <= target) pick = solve(ind-1, nums, target-nums[ind], dp);

        return dp[ind][target] = pick + not_pick;
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int totalsum = 0;
        for(auto it : nums) totalsum += it;
        if((totalsum - target) < 0 || (totalsum - target) % 2 != 0) return 0;
        int k = (totalsum - target)/2;
        vector<vector<int>> dp(n, vector<int>(k+1, -1));
        return solve(n-1, nums, k, dp);
    }
};