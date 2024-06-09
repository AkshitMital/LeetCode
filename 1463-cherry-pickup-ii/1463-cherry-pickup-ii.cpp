// class Solution {
// private:
//     int solve(int row, int col1, int col2, vector<vector<int>>& grid, vector<vector<vector<int>>>& dp){

//         if (col1 < 0 || col1 >= grid[0].size() || col2 < 0 || col2 >= grid[0].size()) return -1e9;

//         if(dp[row][col1][col2] != -1) return dp[row][col1][col2];

//         if(row == grid.size()-1){
//             if(col1 == col2) return grid[row][col1];
//             else return grid[row][col1] + grid[row][col2];
//         }

//         int maxi = -1e9;

//         for(int dj1 = -1; dj1 <= 1; dj1++){
//             for(int dj2 = -1; dj2 <= 1; dj2++){
//                 int new_col1 = col1 + dj1;
//                 int new_col2 = col2 + dj2;
//                 int current_cherries = (col1 == col2) ? grid[row][col1] : grid[row][col1] + grid[row][col2];
//                 maxi = max(maxi, current_cherries + solve(row+1, new_col1, new_col2, grid, dp));
//             }
//         }

//         return dp[row][col1][col2] = maxi;
//     }

// public:
//     int cherryPickup(vector<vector<int>>& grid) {
//         int r = grid.size();
//         int c = grid[0].size();
//         vector<vector<vector<int>>> dp(r, vector<vector<int>>(c, vector<int>(c, -1)));
//         return solve(0, 0, c-1, grid, dp);
//     }
// };


// class Solution {
// public:
//     int cherryPickup(vector<vector<int>>& grid) {
//         int r = grid.size();
//         int c = grid[0].size();
//         vector<vector<vector<int>>> dp(r, vector<vector<int>>(c, vector<int>(c, 0)));

//         for(int j1 = 0; j1 < c; j1++){
//             for(int j2 = 0; j2 < c; j2++){
//                 if(j1 == j2) dp[r-1][j1][j2] = grid[r-1][j1];
//                 else dp[r-1][j1][j2] = grid[r-1][j1] + grid[r-1][j2];
//             }
//         }

//         for(int i = r-2; i >= 0; i--){
//             for(int j1 = 0; j1 < c; j1++){
//                 for(int j2 = 0; j2 < c; j2++){
//                     int maxi = -1e9;

//                     for(int dj1 = -1; dj1 <= 1; dj1++){
//                         for(int dj2 = -1; dj2 <= 1; dj2++){
//                             int new_col1 = j1 + dj1;
//                             int new_col2 = j2 + dj2;
//                             int current_cherries = (j1 == j2) ? grid[i][j1] : grid[i][j1] + grid[i][j2];
//                             if(new_col1 >= 0 && new_col1 < c && new_col2 >= 0 && new_col2 < c) current_cherries += dp[i+1][new_col1][new_col2];
//                             else current_cherries += -1e9;
//                             maxi = max(maxi, current_cherries);
//                         }
//                     }
//                     dp[i][j1][j2] = maxi;
//                 }
//             }
//         }
        

//         return dp[0][0][c-1];
//     }
// };

class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        vector<vector<int>> front(c, vector<int>(c,0));
        vector<vector<int>> curr(c, vector<int>(c,0));

        for(int j1 = 0; j1 < c; j1++){
            for(int j2 = 0; j2 < c; j2++){
                if(j1 == j2) front[j1][j2] = grid[r-1][j1];
                else front[j1][j2] = grid[r-1][j1] + grid[r-1][j2];
            }
        }

        for(int i = r-2; i >= 0; i--){
            for(int j1 = 0; j1 < c; j1++){
                for(int j2 = 0; j2 < c; j2++){
                    int maxi = -1e9;

                    for(int dj1 = -1; dj1 <= 1; dj1++){
                        for(int dj2 = -1; dj2 <= 1; dj2++){
                            int new_col1 = j1 + dj1;
                            int new_col2 = j2 + dj2;
                            int current_cherries = (j1 == j2) ? grid[i][j1] : grid[i][j1] + grid[i][j2];
                            if(new_col1 >= 0 && new_col1 < c && new_col2 >= 0 && new_col2 < c) current_cherries += front[new_col1][new_col2];
                            else current_cherries += -1e9;
                            maxi = max(maxi, current_cherries);
                        }
                    }
                    curr[j1][j2] = maxi;
                }
            }

            front = curr;
        }
        

        return front[0][c-1];
    }
};