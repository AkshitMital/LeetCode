// class Solution {
// private:
//     int solve(int i, int j, string& word1, string& word2, vector<vector<int>>& dp){
//         if(i == 0) return j;
//         if(j == 0) return i;
//         if(dp[i][j] != -1) return dp[i][j];

//         if(word1[i-1] == word2[j-1]) return dp[i][j] = solve(i-1, j-1, word1, word2, dp);
//         int insert = solve(i, j-1, word1, word2, dp);
//         int remove = solve(i-1, j, word1, word2, dp);
//         int replace = solve(i-1, j-1, word1, word2, dp);

//         return dp[i][j] = 1 + min({insert, remove, replace});
//     }
// public:
//     int minDistance(string word1, string word2) {
//         int n = word1.size(), m = word2.size();
//         vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
//         return solve(n, m, word1, word2, dp);
//     }
// };

class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        for(int j = 0; j <= m; j++) dp[0][j] = j;
        for(int i = 0; i <= n; i++) dp[i][0] = i;

        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(word1[i-1] == word2[j-1]) dp[i][j] = dp[i-1][j-1];
                else{
                    int insert = dp[i][j-1];
                    int remove = dp[i-1][j];
                    int replace = dp[i-1][j-1];

                    dp[i][j] = 1 + min({insert, remove, replace});
                }
            }
        }

        return dp[n][m];
    }
};