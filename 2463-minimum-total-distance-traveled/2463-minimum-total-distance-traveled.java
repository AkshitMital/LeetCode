class Solution {
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

        long[][] dp = new long[rSize + 1][fSize + 1];
        for(int r = 1; r <= rSize; r++) dp[r][0] = (long) 1e12;

        for(int r = 1; r <= rSize; r++){
            for(int f = 1; f <= fSize; f++){
                long pick = Math.abs(factories.get(f-1) - robot.get(r-1)) + dp[r - 1][f - 1];
                long not_pick = dp[r][f - 1];
                dp[r][f] = Math.min(pick, not_pick);
            }
        }

        return dp[rSize][fSize];
    }
}