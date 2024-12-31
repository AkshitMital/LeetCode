class Solution {
private:
    int solve(int ind, vector<int>& days, vector<int>& costs, int& n, vector<int>& dp) {
        if(ind >= n) return 0;
        if(dp[ind] != -1) return dp[ind];

        int cost_1 = costs[0] + solve(ind + 1, days, costs, n, dp);

        int j = ind;
        while(j < n && days[j] < days[ind] + 7) j++;
        int cost_7 = costs[1] + solve(j, days, costs, n, dp);

        j = ind;
        while(j < n && days[j] < days[ind] + 30) j++;
        int cost_30 = costs[2] + solve(j, days, costs, n, dp);

        return dp[ind] = min({cost_1, cost_7, cost_30});
    }
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        vector<int> dp(366, -1);
        return solve(0, days, costs, n, dp);
    }
};