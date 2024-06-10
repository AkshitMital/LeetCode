class Solution {
public:
    int solve(int i , vector<int> &arr , int sum , vector<vector<int>> &dp){
        if(sum == 0) return true;
        if(i == 0) return (arr[0] == sum);
        if(dp[i][sum] != -1) return dp[i][sum];
        bool exclude = solve(i-1, arr, sum, dp);
        bool include = false;
        if(sum >= arr[i]) include = solve(i-1, arr, sum-arr[i], dp);

        return dp[i][sum] = exclude | include;
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(auto num : nums) sum += num;
        if(sum%2 != 0) return false;
        sum = sum /2;
        vector<vector<int>> dp(n+1,vector<int>(sum+1,-1));
        return solve(n-1,nums,sum ,dp);
    }
};