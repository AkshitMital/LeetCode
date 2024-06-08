class Solution {
// private:
//     int solve(int row, int col, vector<vector<int>>& dp){
//         if(row == 0 && col == 0){
//             return 1;
//         }
//         if(row < 0 || col < 0){
//             return 0;
//         }

//         if(dp[row][col] != -1) return dp[row][col];

//         int left = solve(row, col-1, dp);
//         int up = solve(row-1, col, dp);

//         return dp[row][col] = left + up;
//     }
public:
    // int uniquePaths(int m, int n) {
    //     vector<vector<int>> dp(m, vector<int>(n,-1));
    //     return solve(m-1,n-1,dp);
    // }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n,0));
        dp[0][0] = 1;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(i == 0 && j == 0) continue;
                int right = (j > 0) ? dp[i][j-1] : 0;
                int down = (i > 0) ? dp[i-1][j] : 0;
                dp[i][j] = right + down;
            }
        }

        return dp[m-1][n-1];
    }
};