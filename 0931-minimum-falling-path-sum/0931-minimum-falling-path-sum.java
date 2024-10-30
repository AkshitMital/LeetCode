class Solution {
    public int minFallingPathSum(int[][] matrix) {
        int n = matrix.length;
        int[][] dp = new int[n][n];
        for(int[] row : dp) Arrays.fill(row, 0);

        for(int col = 0; col < n; col++) dp[0][col] = matrix[0][col];

        for(int row = 1; row < n; row++){
            for(int col = 0; col < n; col++){
                int up = matrix[row][col] + dp[row-1][col];
                int leftDiag = (col > 0) ? matrix[row][col] + dp[row-1][col-1] : Integer.MAX_VALUE;
                int rightDiag = (col < matrix[0].length - 1) ? matrix[row][col] + dp[row-1][col+1] : Integer.MAX_VALUE;

                dp[row][col] = Math.min(up, Math.min(leftDiag, rightDiag));
            }
        }

        int minPath = Integer.MAX_VALUE;
        for(int col = 0; col < n; col++){
            minPath = Math.min(minPath, dp[n-1][col]);
        }

        return minPath;
    }
}