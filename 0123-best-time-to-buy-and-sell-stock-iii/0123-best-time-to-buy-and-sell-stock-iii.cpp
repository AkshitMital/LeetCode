class Solution {
private:
    int solve(int ind, int buy, int cap, vector<int>& prices, vector<vector<vector<int>>>& dp){
        if(cap == 0) return 0;
        if(ind == prices.size()) return 0;
        if(dp[ind][buy][cap] != -1) return dp[ind][buy][cap];
        int price = 0;
        
        if(buy)
            price = max(solve(ind+1, 0, cap, prices, dp) - prices[ind], 
                        0 + solve(ind+1, 1, cap, prices, dp));
        else
            price = max(solve(ind+1, 1, cap-1, prices, dp) + prices[ind],
                        0 + solve(ind+1, 0, cap, prices, dp));

        return dp[ind][buy][cap] = price; 
    }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));
        return solve(0, 1, 2, prices, dp);
    }
};


// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//         int n = prices.size();
//         vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(3, 0)));

//         for(int i = 0; i < n; i++){
//             for(int buy = 0; buy <= 1; buy++){
//                 dp[i][buy][0] = 0;
//             }
//         }

//         for(int buy = 0; buy <= 1; buy++){
//             for(int cap = 0; cap <= 2; cap++){
//                 dp[n][buy][cap] = 0;
//             }
//         }

//         for(int ind = n-1; ind >= 0; ind--){
//             for(int buy = 0; buy <= 1; buy++){
//                 for(int cap = 1; cap <= 2; cap++){
//                     int price = 0;
        
//                     if(buy)
//                         price = max(dp[ind+1][0][cap] - prices[ind], 
//                                     0 + dp[ind+1][1][cap]);
//                     else
//                         price = max(dp[ind+1][1][cap-1] + prices[ind],
//                                     0 + dp[ind+1][0][cap]);

//                     dp[ind][buy][cap] = price; 
//                 }
//             }
//         }

//         return dp[0][1][2];
//     }
// };


// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//         int n = prices.size();
//         vector<vector<int>> prev(2, vector<int>(3, 0));
//         vector<vector<int>> curr(2, vector<int>(3, 0));

//         for(int ind = n-1; ind >= 0; ind--){
//             for(int buy = 0; buy <= 1; buy++){
//                 for(int cap = 1; cap <= 2; cap++){
//                     int price = 0;
        
//                     if(buy)
//                         price = max(prev[0][cap] - prices[ind], 
//                                     0 + prev[1][cap]);
//                     else
//                         price = max(prev[1][cap-1] + prices[ind],
//                                     0 + prev[0][cap]);

//                     curr[buy][cap] = price; 
//                 }
//             }
//             prev = curr;
//         }

//         return prev[1][2];
//     }
// };