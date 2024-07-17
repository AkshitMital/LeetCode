// class Solution {
// private:
//     int solve(int ind, int buy, vector<int>& prices, vector<vector<int>>&
//     dp){
//         if(ind == prices.size()) return 0;

//         if(dp[ind][buy] != -1) return dp[ind][buy];

//         int profit = 0;

//         if(buy) profit = max(solve(ind + 1, 0, prices, dp) - prices[ind],
//                         0 + solve(ind + 1, 1, prices, dp));

//         else profit = max(prices[ind] + solve(ind + 1, 1, prices, dp),
//                         0 + solve(ind + 1, 0, prices, dp));

//         return dp[ind][buy] = profit;
//     }
// public:
//     int maxProfit(vector<int>& prices) {
//         vector<vector<int>> dp(prices.size(), vector<int>(2, -1));
//         return solve(0, 1, prices, dp);
//     }
// };

// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//         int n = prices.size();
//         vector<vector<int>> dp(n + 1, vector<int>(2, 0));
//         dp[n][0] = dp[n][1] = 0;

//         for(int ind = n-1; ind >= 0; ind--){
//             for(int buy = 0; buy <= 1; buy++){
//                 int profit = 0;
//                 if(buy)
//                     profit = max(dp[ind+1][0] - prices[ind], 0 +
//                     dp[ind+1][1]);
//                 else
//                     profit = max(prices[ind] + dp[ind+1][1], 0 +
//                     dp[ind+1][0]);
//                 dp[ind][buy] = profit;
//             }
//         }

//         return dp[0][1];
//     }
// };

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> curr(2, 0), prev(2, 0);
        prev[0] = prev[1] = 0;

        for (int ind = n - 1; ind >= 0; ind--) {
            for (int buy = 0; buy <= 1; buy++) {
                int profit = 0;
                if (buy)
                    profit = max(prev[0] - prices[ind], 0 + prev[1]);
                else
                    profit = max(prices[ind] + prev[1], 0 + prev[0]);

                curr[buy] = profit;
            }
            prev = curr;
        }

        return prev[1];
    }
};