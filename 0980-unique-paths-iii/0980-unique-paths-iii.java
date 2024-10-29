class Solution {
    private int res = 0;
    private void dfs(int row, int col, int[][] grid, int empty, int m, int n){
        if(row < 0 || row >= m || col < 0 || col >= n || grid[row][col] == -1) return;
        if(grid[row][col] == 2){
            if(empty == 0) res++;
            return;
        }

        grid[row][col] = -1;

        dfs(row + 1, col, grid, empty - 1, m, n);
        dfs(row - 1, col, grid, empty - 1, m, n);
        dfs(row, col + 1, grid, empty - 1, m, n);
        dfs(row, col - 1, grid, empty - 1, m, n);

        grid[row][col] = 0;
    }
    public int uniquePathsIII(int[][] grid) {
        int empty = 1, m = grid.length, n = grid[0].length, start_x = 0, start_y = 0;
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 0) empty++;
                if(grid[i][j] == 1){
                    start_x = i;
                    start_y = j;
                }
            }
        }

        dfs(start_x, start_y, grid, empty, m, n);

        return res;
    }
}