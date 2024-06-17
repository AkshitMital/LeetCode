// class Solution {
// private:
//     int solve(int ind, int amount, vector<int>& coins, vector<vector<int>>& dp){
//         if(ind == 0){
//             if(amount % coins[0] == 0) return 1;
//             return 0;
//         }

//         if(dp[ind][amount] != -1) return dp[ind][amount];
//         int not_pick = solve(ind-1, amount, coins, dp);
//         int pick = 0;
//         if(coins[ind] <= amount) pick = solve(ind, amount-coins[ind], coins, dp);

//         return dp[ind][amount] = pick + not_pick;
//     }
// public:
//     int change(int amount, vector<int>& coins) {
//         int n = coins.size();
//         vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
//         return solve(n-1, amount, coins, dp);
//     }
// };

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, 0));
        for(int i = 0; i <= amount; i++){
            if(i%coins[0] == 0) dp[0][i] = 1;
        }

        for(int ind = 1; ind<n; ind++){
            for(int target = 0; target <= amount; target++){
                int not_pick = dp[ind-1][target];
                int pick = (coins[ind] <= target) ? dp[ind][target-coins[ind]] : 0;
                dp[ind][target] = pick + not_pick;
            }
        }

        return dp[n-1][amount];
    }
};