class Solution {
private:
    int solve(int player, int ind, int M, vector<int>& piles, vector<vector<vector<int>>>& dp, int& n){
        if(ind >= n) return 0;
        if(dp[player][ind][M] != -1) return dp[player][ind][M];
        int result = (player == 1) ? INT_MIN : INT_MAX;
        int stones = 0;

        for(int X = 1; X <= min(2*M, n-ind); X++){
            stones += piles[ind + X - 1];
            
            if(player == 1){
                result = max(result, stones + solve(0, ind + X, max(M,X), piles, dp, n));
            }
            else{
                result = min(result, solve(1, ind + X, max(M,X), piles, dp, n));
            }
        }

        return dp[player][ind][M] = result;
    }
public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        vector<vector<vector<int>>> dp(2, vector<vector<int>>(n+1, vector<int>(n+1, -1)));
        // 1 -> Alice
        // 0 -> Bob
        return solve(1, 0, 1, piles, dp, n);
    }
};