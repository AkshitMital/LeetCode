class Solution {
private:
    int solve(int row, int col, vector<vector<int>>& dp, vector<vector<int>>& grid){
        if(row == 0 && col == 0) return grid[row][col];
        if(row < 0 || col < 0) return INT_MAX;

        if(dp[row][col] != -1) return dp[row][col];

        int left = solve(row, col - 1, dp, grid);
        int up = solve(row - 1, col, dp, grid);

        if (left != INT_MAX) left += grid[row][col];
        if (up != INT_MAX) up += grid[row][col];

        return dp[row][col] = min(left, up);
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n,-1));
        return solve(m-1, n-1, dp , grid);
    }
};