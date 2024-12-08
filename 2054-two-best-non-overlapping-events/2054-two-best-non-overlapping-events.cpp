class Solution {
private:
    int n;
    int UpperBound(vector<vector<int>>& events, int endTime){
        int l = 0, r = n-1, result = n;
        while(l <= r){
            int mid = l + (r - l)/2;
            if(events[mid][0] > endTime){
                result = mid;
                r = mid - 1;
            }
            else l = mid + 1;
        }

        return result;
    }
    int solve(int i, vector<vector<int>>& events, int count, vector<vector<int>>& dp){
        if(count == 2 || i >= n) return 0;

        if(dp[i][count] != -1) return dp[i][count];
        int nextValidElement = UpperBound(events, events[i][1]);
        int take = events[i][2] + solve(nextValidElement, events, count+1, dp);
        int not_take = solve(i+1, events, count, dp);

        return dp[i][count] = max(take, not_take);
    }
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        n = events.size();
        sort(events.begin(), events.end());
        vector<vector<int>> dp(n+1, vector<int>(3, -1));
        return solve(0, events, 0, dp);
    }
};