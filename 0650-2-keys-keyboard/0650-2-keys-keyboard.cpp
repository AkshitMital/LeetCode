class Solution {
private:
    int solve(int currA, int clip, int& n, vector<vector<int>>& dp){
        if(currA > n) return 1e9;
        if(currA == n) return 0;
        if(dp[currA][clip] != -1) return dp[currA][clip];

        int paste = 1 + solve(clip + currA, clip, n, dp);
        int copyAllPaste = 1 + 1 + solve(currA + currA, currA, n, dp);

        return dp[currA][clip] = min(paste, copyAllPaste);
    }
public:
    int minSteps(int n) {
        if(n == 1) return 0;
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        return 1 + solve(1, 1, n, dp);
    }
};