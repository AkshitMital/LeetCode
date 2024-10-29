class Solution {
    private int solve(int row, int col, int[][] grid, int m, int n){
        if(row >= m || row < 0 || col >= n)
            return 0;
        
        int maxMoves = 0;
        if(row - 1 >= 0 && col + 1 < n && grid[row][col] < grid[row-1][col+1])
            maxMoves = Math.max(maxMoves, 1 + solve(row - 1, col + 1, grid, m, n));

        if(col+1 < n && grid[row][col] < grid[row][col+1])
            maxMoves = Math.max(maxMoves, 1 + solve(row, col + 1, grid, m, n));

        if(row + 1 < m && col + 1 < n && grid[row][col] < grid[row+1][col+1])
            maxMoves = Math.max(maxMoves, 1 + solve(row + 1, col + 1, grid, m, n));

        return maxMoves;
    }

    public int maxMoves(int[][] grid) {
        int m = grid.length;
        int n = grid[0].length;

        int maxMoves = 0;
        for(int i = 0; i < m; i++){
            int moves = solve(i, 0, grid, m, n);
            maxMoves = Math.max(maxMoves, moves);
        }

        return maxMoves;
    }
}