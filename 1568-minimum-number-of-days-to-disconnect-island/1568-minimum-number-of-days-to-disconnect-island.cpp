class Solution {
private:
    void dfs(int row, int col, vector<vector<int>>& grid, int& m, int& n){
        grid[row][col] = 0;
        int delrow[4] = {0, -1, 0, 1};
        int delcol[4] = {-1, 0, 1, 0};

        for(int i = 0; i < 4; i++){
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];

            if(nrow >= 0 && nrow < m && ncol >= 0 && ncol < n && grid[nrow][ncol]) 
                dfs(nrow, ncol, grid, m, n);
        }
    }
    int numberofislands(vector<vector<int>> grid, int& m, int& n){
        int islands = 0;
        // vector<vector<int>> vis(m, vector<int>(n, 0));
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j]){
                    dfs(i, j, grid, m, n);
                    islands++;
                }
            }
        }

        return islands;
    }
public:
    int minDays(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int numislands = numberofislands(grid, m, n);
        // Case 0
        if(numislands > 1 || numislands == 0) return 0;

        // Case 1
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j]){
                    grid[i][j] == 0;
                    int totalislands = numberofislands(grid, m, n);
                    if(totalislands == 0 || totalislands > 1) return 1;
                }
            }
        }

        // Case 2
        return 2;
    }
};