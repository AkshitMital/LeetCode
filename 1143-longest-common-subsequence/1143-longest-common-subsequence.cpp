// class Solution {
// private:
//     int solve(int ind1, int ind2, string text1, string text2, vector<vector<int>>& dp){
//         if(ind1 == 0 || ind2 == 0) return 0;

//         if(dp[ind1][ind2] != -1) return dp[ind1][ind2];

//         if(text1[ind1-1] == text2[ind2-1]) return dp[ind1][ind2] = 1 + solve(ind1-1, ind2-1, text1, text2, dp);

//         return dp[ind1][ind2] = max(solve(ind1-1, ind2, text1, text2, dp), solve(ind1, ind2-1, text1, text2, dp));
//     }
// public:
//     int longestCommonSubsequence(string text1, string text2) {
//         vector<vector<int>> dp(text1.size()+1,vector<int>(text2.size()+1,-1));
//         return solve(text1.size(), text2.size(), text1, text2, dp);
//     }
// };

// class Solution {
// public:
//     int longestCommonSubsequence(string text1, string text2) {
//         int n = text1.size(), m = text2.size();
//         vector<vector<int>> dp(n+1,vector<int>(m+1,0));

//         for(int i = 0 ; i <= n; i++) dp[i][0] = 0;
//         for(int i = 0 ; i <= m; i++) dp[0][i] = 0;

//         for(int i = 1; i <= n; i++){
//             for(int j = 1; j <= m; j++){
//                 if(text1[i-1] == text2[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
//                 else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
//             }
//         }

//         return dp[n][m];
//     }
// };

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size(), m = text2.size();
        vector<int> prev(m+1,0), curr(m+1,0);

        for(int i = 0 ; i <= m; i++) prev[i] = 0;

        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(text1[i-1] == text2[j-1]) curr[j] = 1 + prev[j-1];
                else curr[j] = max(prev[j], curr[j-1]);
            }
            prev = curr;
        }

        return prev[m];
    }
};