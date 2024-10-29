// class Solution {
//     private int solve(int row, int col, int[][] grid, int[][] dp, int m, int n){
//         if(row >= m || row < 0 || col >= n)
//             return 0;
        
//         if(dp[row][col] != -1) return dp[row][col];

//         int maxMoves = 0;
//         if(row - 1 >= 0 && col + 1 < n && grid[row][col] < grid[row-1][col+1])
//             maxMoves = Math.max(maxMoves, 1 + solve(row - 1, col + 1, grid, dp, m, n));

//         if(col + 1 < n && grid[row][col] < grid[row][col+1])
//             maxMoves = Math.max(maxMoves, 1 + solve(row, col + 1, grid, dp, m, n));

//         if(row + 1 < m && col + 1 < n && grid[row][col] < grid[row+1][col+1])
//             maxMoves = Math.max(maxMoves, 1 + solve(row + 1, col + 1, grid, dp, m, n));

//         return dp[row][col] = maxMoves;
//     }

//     public int maxMoves(int[][] grid) {
//         int m = grid.length;
//         int n = grid[0].length;
//         int[][] dp = new int[m][n];
//         for(int[] row : dp) Arrays.fill(row, -1);

//         int maxMoves = 0;
//         for(int i = 0; i < m; i++){
//             int moves = solve(i, 0, grid, dp, m, n);
//             maxMoves = Math.max(maxMoves, moves);
//         }

//         return maxMoves;
//     }
// }

// 

class Solution {
    public int maxMoves(int[][] grid) {
        int m = grid.length;
        int n = grid[0].length;
        int[] current = new int[m];
        int[] next = new int[m];

        for (int col = n - 2; col >= 0; col--) {
            int[] temp = current;
            current = next;
            next = temp;
            Arrays.fill(current, 0);

            for (int row = 0; row < m; row++) {
                int maxMoves = 0;

                if (grid[row][col] < grid[row][col + 1]) {
                    maxMoves = Math.max(maxMoves, 1 + next[row]);
                }

                if (row > 0 && grid[row][col] < grid[row - 1][col + 1]) {
                    maxMoves = Math.max(maxMoves, 1 + next[row - 1]);
                }

                if (row < m - 1 && grid[row][col] < grid[row + 1][col + 1]) {
                    maxMoves = Math.max(maxMoves, 1 + next[row + 1]);
                }

                current[row] = maxMoves;
            }
        }

        int maxMoves = 0;
        for(int i = 0; i < m; i++){
            int moves = current[i];
            maxMoves = Math.max(maxMoves, moves);
        }

        return maxMoves;
    }
}