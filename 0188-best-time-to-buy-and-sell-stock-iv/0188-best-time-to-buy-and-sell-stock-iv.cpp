// class Solution {
// private:
//     int solve(int ind, int transactions, vector<int>& prices, vector<vector<int>>& dp, int k){
//         if(ind == prices.size() || transactions == 2*k) return 0;
//         if(dp[ind][transactions] != -1) return dp[ind][transactions];
//         int price = 0;

//         if(transactions % 2 == 0) //buy
//             price = max(solve(ind+1, transactions+1, prices, dp, k) - prices[ind],
//                         solve(ind+1, transactions, prices, dp, k));
//         else //sell
//             price = max(solve(ind+1, transactions+1, prices, dp, k) + prices[ind],
//                         solve(ind+1, transactions, prices, dp, k));

//         return dp[ind][transactions] = price;
//     }
// public:
//     int maxProfit(int k, vector<int>& prices) {
//         int n = prices.size();
//         vector<vector<int>> dp(n, vector<int>(2*k, -1));
//         return solve(0, 0, prices, dp, k);
//     }
// };

// class Solution {
// public:
//     int maxProfit(int k, vector<int>& prices) {
//         int n = prices.size();
//         vector<vector<int>> dp(n+1, vector<int>(2*k+1, 0));

//         for(int ind = n-1; ind >= 0; ind--){
//             for(int transactions = 2*k-1; transactions >= 0; transactions--){
//                 int price = 0;
//                 if(transactions % 2 == 0) //buy
//                     price = max(dp[ind+1][transactions+1] - prices[ind],
//                                 dp[ind+1][transactions]);
//                 else //sell
//                     price = max(dp[ind+1][transactions+1] + prices[ind],
//                                 dp[ind+1][transactions]);

//                 dp[ind][transactions] = price;
//             }
//         }

//         return dp[0][0];
//     }
// };

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<int> prev(2*k+1, 0), curr(2*k+1, 0);

        for(int ind = n-1; ind >= 0; ind--){
            for(int transactions = 2*k-1; transactions >= 0; transactions--){
                int price = 0;
                if(transactions % 2 == 0) //buy
                    price = max(prev[transactions+1] - prices[ind],
                                prev[transactions]);
                else //sell
                    price = max(prev[transactions+1] + prices[ind],
                                prev[transactions]);

                curr[transactions] = price;
            }
            prev = curr;
        }

        return prev[0];
    }
};