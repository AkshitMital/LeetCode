class Solution {
public:
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        vector<int> factories;
        for(auto row : factory){
            for(int i = 0; i < row[1]; i++) factories.push_back(row[0]);
        }

        sort(robot.begin(), robot.end());
        sort(factories.begin(), factories.end());

        int rSize = robot.size();
        int fSize = factories.size();
        long long ans = 0;
        if(rSize == fSize){
            for(int i = 0; i < rSize; i++){
                ans += abs(factories[i] - robot[i]);
            }
            return ans;
        }

        vector<vector<long long>> dp(rSize+1, vector<long long>(fSize+1, 0));
        for(int r = 1; r <= rSize; r++) dp[r][0] = (long long) 1e12;

        for(int r = 1; r <= rSize; r++){
            for(int f = 1; f <= fSize; f++){
                long long pick = abs(factories[f - 1] - robot[r - 1]) + dp[r - 1][f - 1];
                long long not_pick = dp[r][f - 1];
                dp[r][f] = min(pick, not_pick);
            }
        }

        return dp[rSize][fSize];
    }
};