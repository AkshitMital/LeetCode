// class Solution {
// private:
//     int solve(int row, int col, vector<vector<int>>& matrix, vector<vector<int>>& dp){
//         if(row == 0) return matrix[row][col];
//         if(dp[row][col] != -1) return dp[row][col];
        // int up = matrix[row][col] + solve(row-1, col, matrix, dp);
        // int left_diag = matrix[row][col] + ((col != 0) ? solve(row-1, col-1, matrix, dp) : 1e9);
        // int right_diag = matrix[row][col] + ((col != matrix[0].size()-1) ? solve(row-1, col+1, matrix, dp) : 1e9);
//         return dp[row][col] = min({up, left_diag, right_diag});
//     }
// public:
//     int minFallingPathSum(vector<vector<int>>& matrix) {
        // int n = matrix.size();
        // int minPathSum = INT_MAX;
        // vector<vector<int>> dp(n, vector<int>(n,-1));
        // for(int col = 0; col < n; col++) {
        //     minPathSum = min(minPathSum, solve(n-1, col, matrix, dp));
        // }
        // return minPathSum;
//     }
// };

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int>(n,0));
        for(int col = 0; col < n; col++){
            dp[0][col] = matrix[0][col]; 
        }

        for(int row = 1; row<n; row++){
            for(int col = 0; col< n; col++){
                int up = matrix[row][col] + dp[row-1][col];
                int left_diag = matrix[row][col] + ((col != 0) ? dp[row-1][col-1] : 1e9);
                int right_diag = matrix[row][col] + ((col != matrix[0].size()-1) ? dp[row-1][col+1] : 1e9);
                dp[row][col] = min({up, left_diag, right_diag});
            }
        }

        int minPathSum = INT_MAX;
        for(int col = 0; col < n; col++) {
            minPathSum = min(minPathSum, dp[n-1][col]);
        }
        return minPathSum;
    }
};
