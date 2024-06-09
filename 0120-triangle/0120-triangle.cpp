class Solution {
private:
    int solve(int row, int col, vector<vector<int>>& triangle, vector<vector<int>>& dp){
        if(row == triangle.size()-1){
            return triangle[row][col];
        }

        if(dp[row][col] != -1) return dp[row][col];

        int down = triangle[row][col] + solve(row+1, col, triangle, dp);
        int diagnol = triangle[row][col] + solve(row+1, col+1, triangle, dp);

        return dp[row][col] = min(diagnol, down);
    }
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(n,-1));
        return solve(0, 0, triangle, dp);
    }
};