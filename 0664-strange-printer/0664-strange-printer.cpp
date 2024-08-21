class Solution {
private:
    int solve(string& s, int i, int j, vector<vector<int>>& dp){
        if(i == j) return 1;
        if(dp[i][j] != -1) return dp[i][j];
        int minTurn = INT_MAX;
        for(int k = i; k < j; k++){
            int left = solve(s, i, k, dp);
            int right = solve(s, k+1, j, dp);

            minTurn = min(minTurn, left + right);
        }
        return dp[i][j] = (s[i] == s[j]) ? minTurn - 1 : minTurn;
    }
public:
    int strangePrinter(string s) {
        int n = s.length();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return solve(s, 0, n-1, dp);
    }
};