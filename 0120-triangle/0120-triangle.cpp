// class Solution {
// private:
//     int solve(int row, int col, vector<vector<int>>& triangle, vector<vector<int>>& dp){
//         if(row == triangle.size() - 1){
//             return triangle[row][col];
//         }

//         if(dp[row][col] != -1) return dp[row][col];

//         int down = triangle[row][col] + solve(row+1, col, triangle, dp);
//         int diagnol = triangle[row][col] + solve(row+1, col+1, triangle, dp);

//         return dp[row][col] = min(diagnol, down);
//     }
// public:
//     int minimumTotal(vector<vector<int>>& triangle) {
//         int n = triangle.size();
//         vector<vector<int>> dp(n, vector<int>(n,-1));
//         return solve(0, 0, triangle, dp);
//     }
// };

// class Solution {
// public:
//     int minimumTotal(vector<vector<int>>& triangle) {
//         int n = triangle.size();
//         vector<vector<int>> dp(n, vector<int>(n,0));

//         for(int i = n-1; i >= 0; i--){
//             for(int j = i; j >= 0; j--){
//                 if(i == n-1) dp[i][j] = triangle[i][j];
//                 else{
//                     int down = triangle[i][j] + dp[i+1][j];
//                     int diagnol = triangle[i][j] + dp[i+1][j+1];
//                     dp[i][j] = min(diagnol, down);
//                 }
//             }
//         }

//         return dp[0][0];
//     }
// };

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> front(n), curr(n);
        for(int j = 0; j < n; j++) front[j] = triangle[n-1][j];
        for(int i = n-2; i >= 0; i--){
            for(int j = i; j >= 0; j--){
                int down = triangle[i][j] + front[j];
                int diagnol = triangle[i][j] + front[j+1];
                curr[j] = min(diagnol, down);
            }
            front = curr;
        }

        return front[0];
    }
};