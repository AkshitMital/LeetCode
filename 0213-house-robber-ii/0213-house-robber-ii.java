class Solution {
    private int solve(int ind, int[] nums, int[] dp){
        if(ind == 0) return nums[ind];
        if(ind < 0) return 0;

        if(dp[ind] != -1) return dp[ind];

        int take = nums[ind] + solve(ind-2, nums, dp);
        int not_take = 0 + solve(ind-1, nums, dp);

        return dp[ind] = Math.max(take, not_take);
    }
    public int rob(int[] nums) {
        int n = nums.length;
        if(n == 1) return nums[0];
        int[] nums1 = new int[n-1];
        int[] nums2 = new int[n-1];
        for(int i = 0; i < n; i++){
            if(i > 0) nums1[i - 1] = nums[i];
            if(i < n - 1) nums2[i] = nums[i];
        }
        n = nums1.length;
        int[] dp = new int[n];
        Arrays.fill(dp, -1);
        int left = solve(n-1, nums1, dp);
        Arrays.fill(dp, -1);
        int right = solve(n-1, nums2, dp);
        return Math.max(left, right);
    }
}