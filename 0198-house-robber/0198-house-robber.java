class Solution {
    private int solve(int ind, int[] nums, int[] dp){
        if(ind == 0) return nums[ind];
        if(ind < 0) return 0;

        if(dp[ind] != -1) return dp[ind];

        int pick = nums[ind] + solve(ind - 2, nums, dp);
        int not_pick = 0 + solve(ind-1, nums, dp);

        return dp[ind] = Math.max(pick, not_pick);
    }
    public int rob(int[] nums) {
        int n = nums.length;
        int[] dp = new int[n];
        Arrays.fill(dp, -1);
        return solve(n-1, nums, dp);
    }
}