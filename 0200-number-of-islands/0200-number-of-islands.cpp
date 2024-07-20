class Solution {
private:
    // void dfs(int row, int col, int delrow[], int delcol[], vector<vector<char>>& grid, int m, int n){
    //     grid[row][col] = '#';
    //     for(int i = 0 ; i < 4; i++){
    //         int nrow = row + delrow[i];
    //         int ncol = col + delcol[i];
    //         if(nrow >= 0 && nrow < m && ncol >=0 && ncol < n && grid[nrow][ncol] == '1'){
    //             dfs(nrow,ncol,delrow,delcol,grid,m,n);
    //         }
    //     }
    // }
    void dfs(int row, int col, vector<vector<char>>& grid, int m, int n){
        if(row < 0 || row>=m || col < 0 || col>=n || grid[row][col] == '0'){
            return;
        }

        grid[row][col] = '0';

        dfs(row, col - 1, grid,m,n);
        dfs(row - 1 , col, grid,m,n);
        dfs(row, col + 1, grid,m,n);
        dfs(row + 1, col, grid,m,n);
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int cnt = 0;
        // int delrow[4] = {-1,0,1,0};
        // int delcol[4] = {0,-1,0,1};
        // for(int i = 0; i < m; i++){
        //     for(int j = 0; j < n; j++){
        //         if(grid[i][j] == '1'){
        //             dfs(i,j,delrow,delcol,grid,m,n);
        //             cnt++;
        //         }
        //     }
        // }
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == '1'){
                    cnt++;
                    dfs(i,j,grid,m,n);
                }
            }
        }

        return cnt;
    }
};