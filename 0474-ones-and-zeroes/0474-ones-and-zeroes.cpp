class Solution {
private:
    int solve(int ind, vector<pair<int,int>>& count, int m, int n, vector<vector<vector<int>>>& dp){
        if(ind < 0) return 0;
        if(m < 0 || n < 0) return INT_MIN;

        if(dp[ind][m][n] != -1) return dp[ind][m][n];

        int not_take = 0 + solve(ind-1, count, m, n, dp);
        int take = INT_MIN;
        if(m >= count[ind].first && n >= count[ind].second) {
            take = 1 + solve(ind-1, count, m - count[ind].first, n - count[ind].second, dp);
        }

        return dp[ind][m][n] = max(take, not_take);
    }
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<pair<int,int>> count; // {zeroes, ones}
        for(int i = 0; i < strs.size(); i++){
            int cnt0 = 0;
            int cnt1 = 0;
            for(int j = 0; j < strs[i].length(); j++){
                if(strs[i][j] == '0') cnt0++;
                if(strs[i][j] == '1') cnt1++;
            }
            count.push_back({cnt0, cnt1});
        }

        vector<vector<vector<int>>> dp(strs.size(), vector<vector<int>>(m+1, vector<int>(n+1, -1)));
        return solve(strs.size() - 1, count, m, n, dp);
    }
};