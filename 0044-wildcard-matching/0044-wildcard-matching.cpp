// class Solution {
// private:
//     bool solve(int i, int j, string& s, string& p, vector<vector<int>>& dp){
//         if(i==0 && j==0) return true;
//         if(j==0 && i>0) return false;
//         if(i==0 && j>0){
//             for(int k = 1; k <= j; k++){
//                 if(p[k-1] != '*') return false;
//             }
//             return true;
//         }
//         if(dp[i][j] != -1) return dp[i][j];
//         if(s[i-1] == p[j-1] || p[j-1] == '?') return dp[i][j] = solve(i-1, j-1, s, p, dp);
//         if(p[j-1] == '*') return dp[i][j] = solve(i, j-1, s, p, dp) | solve(i-1, j, s, p, dp);
//         return dp[i][j] = false;
//     }
// public:
//     bool isMatch(string s, string p) {
//         int n = s.length(), m = p.length();
//         vector<vector<int>> dp(n+1, vector<int>(m+1,-1)); 
//         return solve(n, m, s, p, dp);
//     }
// };

class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.length(), m = p.length();
        vector<vector<bool>> dp(n+1, vector<bool>(m+1,false)); 
        dp[0][0] = true;
        for(int i=1; i<=n; i++) dp[i][0] = false;
        for(int j=1; j<=m; j++){
            bool flag = true;
            for(int k = 1; k <= j; k++){
                if(p[k-1] != '*') {
                    flag = false;
                    break;
                }
            }
            dp[0][j] = flag;
        }


        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(s[i-1] == p[j-1] || p[j-1] == '?') dp[i][j] = dp[i-1][j-1];
                else if(p[j-1] == '*') dp[i][j] = dp[i][j-1] | dp[i-1][j];
                else dp[i][j] = false;
            }
        }


        return dp[n][m];
    }
};

// class Solution {
// public:
//     bool isMatch(string s, string p) {
//         int n = s.length(), m = p.length();
//         vector<bool> prev(m+1,false), curr(m+1, false); 
//         prev[0] = true;
//         for(int j=1; j<=m; j++){
//             bool flag = true;
//             for(int k = 1; k <= j; k++){
//                 if(p[k-1] != '*') {
//                     flag = false;
//                     break;
//                 }
//             }
//             prev[j] = flag;
//         }


//         for(int i = 1; i <= n; i++){
//             for(int j = 1; j <= m; j++){
//                 if(s[i-1] == p[j-1] || p[j-1] == '?') curr[j] = prev[j-1];
//                 else if(p[j-1] == '*') curr[j] = curr[j-1] | prev[j];
//                 else curr[j] = false;
//             }
//             prev = curr;
//         }


//         return prev[m];
//     }
// };