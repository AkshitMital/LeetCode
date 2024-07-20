class Solution {
    int solve(int n, vector<int>& dp){
        if(n == 0) return 1;
        if(dp[n] != -1) return dp[n];

        int one = solve(n-1, dp);
        int two = (n > 1) ? solve(n-2, dp) : 0;

        return dp[n] = one + two;
    }
public:
    int climbStairs(int n) {
        vector<int> dp(n+1, -1);
        return solve(n, dp);
    }
};