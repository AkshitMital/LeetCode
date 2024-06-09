class Solution {
private:
    int solve(int row, int col1, int col2, vector<vector<int>>& grid, vector<vector<vector<int>>>& dp){
        // Check for out-of-bounds conditions
        if (col1 < 0 || col1 >= grid[0].size() || col2 < 0 || col2 >= grid[0].size()) return -1e9;

        // If the result is already computed, return it
        if(dp[row][col1][col2] != -1) return dp[row][col1][col2];

        // Base case: if it's the last row
        if(row == grid.size()-1){
            if(col1 == col2) return grid[row][col1];
            else return grid[row][col1] + grid[row][col2];
        }

        int maxi = -1e9;

        // Explore all possible movements for both columns
        for(int dj1 = -1; dj1 <= 1; dj1++){
            for(int dj2 = -1; dj2 <= 1; dj2++){
                int new_col1 = col1 + dj1;
                int new_col2 = col2 + dj2;
                int current_cherries = (col1 == col2) ? grid[row][col1] : grid[row][col1] + grid[row][col2];
                maxi = max(maxi, current_cherries + solve(row+1, new_col1, new_col2, grid, dp));
            }
        }

        // Memoize the result before returning
        return dp[row][col1][col2] = maxi;
    }

public:
    int cherryPickup(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        // Initialize the dp array with -1
        vector<vector<vector<int>>> dp(r, vector<vector<int>>(c, vector<int>(c, -1)));
        // Start the recursion from the top row, first column and last column
        return solve(0, 0, c-1, grid, dp);
    }
};
