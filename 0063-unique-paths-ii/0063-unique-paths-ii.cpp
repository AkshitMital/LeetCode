class Solution {
private:
    int solve(int row, int col, vector<vector<int>>& dp, vector<vector<int>>& obstacleGrid){
        if(row>=0 && col>=0 && obstacleGrid[row][col]) return 0;
        if(row == 0 && col == 0) return 1;
        if(row < 0 || col < 0) return 0;
        if(dp[row][col] != -1) return dp[row][col];

        int left = solve(row, col-1, dp, obstacleGrid);
        int up = solve(row-1, col, dp, obstacleGrid);

        return dp[row][col] = left + up;
    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n,-1));
        return solve(m-1, n-1, dp, obstacleGrid);
    }
};


// class Solution {
// public:
//     int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
//         int m = obstacleGrid.size();
//         int n = obstacleGrid[0].size();
//         vector<vector<int>> dp(m, vector<int>(n,0));

//         for(int i = 0; i < m; i++){
//             for(int j = 0; j < n; j++){
//                 if(obstacleGrid[i][j]) continue;
//                 if(i == 0 && j == 0) dp[i][j] = 1;
//                 else{
//                     int left = (j > 0) ? dp[i][j-1] : 0;
//                     int up = (i > 0) ? dp[i-1][j] : 0;
//                     dp[i][j] = left + up;
//                 }
//             }
//         }

//         return dp[m-1][n-1];
//     }
// };