class Solution {
    private long solve(int r, int f, List<Integer> robot, List<Integer> factories, long[][] dp){
        if(r >= 0 && f == -1) return (long)1e12;
        if(r == -1 || f == -1) return 0;

        if(dp[r][f] != -1) return dp[r][f];

        long pick = Math.abs(factories.get(f) - robot.get(r)) + solve(r - 1, f - 1, robot, factories, dp);
        long not_pick = solve(r, f - 1, robot, factories, dp);

        return dp[r][f] = Math.min(pick, not_pick);
    }
    public long minimumTotalDistance(List<Integer> robot, int[][] factory) {
        List<Integer> factories = new ArrayList<>();
        for(int[] row : factory){
            for(int i = 0; i < row[1]; i++) factories.add(row[0]);
        }

        Collections.sort(robot);
        Collections.sort(factories);

        int rSize = robot.size();
        int fSize = factories.size();
        long ans = 0;
        if(rSize == fSize){
            for(int i = 0; i < rSize; i++){
                ans += Math.abs(factories.get(i) - robot.get(i));
            }
            return ans;
        }

        long[][] dp = new long[rSize][fSize];
        for(long[] row : dp) Arrays.fill(row, -1);
        return solve(rSize-1, fSize-1, robot, factories, dp);
    }
}