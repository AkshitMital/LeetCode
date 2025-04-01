class Solution {
private:
    long long ans(int idx, vector<vector<int>>& questions, int n, vector<long long>& dp) {
        if(idx >= n) return 0;
        if(dp[idx] != -1) return dp[idx];

        long long solve = questions[idx][0] + ans(idx + questions[idx][1] + 1, questions, n, dp);
        long long skip = ans(idx + 1, questions, n, dp);

        return dp[idx] = max(skip, solve);
    }
    
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<long long> dp(n+1, -1);
        return ans(0, questions, n, dp);
    }
};