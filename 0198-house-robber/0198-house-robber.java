class Solution {
    public int rob(int[] nums) {
        int n = nums.length;
        int[] dp = new int[n];
        Arrays.fill(dp, 0);
        dp[0] = nums[0];

        for(int ind = 1; ind < n; ind++){
            int pick = nums[ind];
            if(ind > 1) pick = nums[ind] + dp[ind - 2];
            int not_pick = 0 + dp[ind-1];
            dp[ind] = Math.max(pick, not_pick);
        }

        return dp[n-1];
    }
}