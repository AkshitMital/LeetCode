class Solution {
private:
    int solve(int ind, int buy, vector<int>& prices, vector<vector<int>>& dp){
        if(ind == prices.size()) return 0;

        if(dp[ind][buy] != -1) return dp[ind][buy];

        int profit = 0;

        if(buy) profit = max(solve(ind + 1, 0, prices, dp) - prices[ind], 
                        0 + solve(ind + 1, 1, prices, dp));

        else profit = max(prices[ind] + solve(ind + 1, 1, prices, dp), 
                        0 + solve(ind + 1, 0, prices, dp));

        return dp[ind][buy] = profit;
    }
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(), vector<int>(2, -1));
        return solve(0, 1, prices, dp);
    }
};