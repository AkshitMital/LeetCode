class Solution {
    private boolean isSubsetSum(int[] arr, int sum){
        int n = arr.length;
        boolean[][] dp = new boolean[n][sum+1];
        for(boolean[] row : dp) Arrays.fill(row, false);
        
        for(int i = 0; i < n; i++) dp[i][0] = true;
        
        if (arr[0] <= sum) dp[0][arr[0]] = true;
        
        for(int i = 1; i < n; i++){
            for(int target = 1; target <= sum; target++){
                boolean exclude = dp[i-1][target];
                boolean include = false;
                if(target >= arr[i]) include = dp[i-1][target-arr[i]];
                
                dp[i][target] = include | exclude;
            }
        }
        
        return dp[n-1][sum];
    }

    public boolean canPartition(int[] nums) {
        int sum = 0;
        for(int num : nums) sum += num;

        if(sum % 2 != 0) return false;

        int target = sum/2;

        return isSubsetSum(nums, target);
    }
}