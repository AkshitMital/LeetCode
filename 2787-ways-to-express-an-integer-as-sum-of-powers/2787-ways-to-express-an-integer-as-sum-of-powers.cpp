class Solution {
private:
    vector<vector<int>> dp;
    int MOD = 1e9 + 7;
public:
    int solve(int num, int n, int x) {
        if(num == 0) return 1;
        if(num < 0) return 0;
        int temp = pow(n, x);
        if(temp > num) return 0;
        if(dp[num][n] != -1) return dp[num][n];
        int take = solve(num - temp, n + 1, x);
        int not_take = solve(num, n + 1, x);

        return dp[num][n] = (take + not_take) % MOD;
    }
    int numberOfWays(int n, int x) {
        dp.resize(n + 1, vector<int>(n + 1, -1));
        return solve(n, 1, x);
    }
};