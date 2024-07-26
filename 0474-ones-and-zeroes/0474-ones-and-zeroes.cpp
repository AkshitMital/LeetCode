class Solution {
private:
    int solve(int ind, vector<pair<int, int>>& count, int m, int n, vector<vector<vector<int>>>& dp) {
        if (ind == 0) return 0;
        if (dp[ind][m][n] != -1) return dp[ind][m][n];

        int not_take = solve(ind - 1, count, m, n, dp);
        int take = INT_MIN;
        if (m >= count[ind - 1].first && n >= count[ind - 1].second) {
            take = 1 + solve(ind - 1, count, m - count[ind - 1].first, n - count[ind - 1].second, dp);
        }

        return dp[ind][m][n] = max(take, not_take);
    }

public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<pair<int, int>> count; // {zeroes, ones}
        for (int i = 0; i < strs.size(); i++) {
            int cnt0 = 0, cnt1 = 0;
            for (char ch : strs[i]) {
                if (ch == '0') cnt0++;
                if (ch == '1') cnt1++;
            }
            count.push_back({cnt0, cnt1});
        }

        vector<vector<vector<int>>> dp(strs.size() + 1, vector<vector<int>>(m + 1, vector<int>(n + 1, -1)));
        return solve(strs.size(), count, m, n, dp);
    }
};
