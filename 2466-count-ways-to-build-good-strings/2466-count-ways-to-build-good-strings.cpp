class Solution {
private:
    const int MOD = 1e9 + 7;

    int solve(int sz, int low, int high, int one, int zero, vector<int>& dp){
        if(sz > high) return 0;

        if(dp[sz] != -1) return dp[sz];

        int take1 = solve(sz + one, low, high, one, zero, dp) % MOD;
        int take0 = solve(sz + zero, low, high, one, zero, dp) % MOD;
        int self = 0;

        if(sz >= low && sz <= high) self = 1;

        return dp[sz] = (self + take1 + take0) % MOD;
    }

public:
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<int> dp(high + 1, -1);
        return solve(0, low, high, one, zero, dp);
    }
};