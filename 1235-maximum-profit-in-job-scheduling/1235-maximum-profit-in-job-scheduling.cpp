class Solution {
private:
    vector<int> dp;

    int findNextJob(int current_index, vector<vector<int>>& jobs) {
        int low = current_index + 1;
        int high = jobs.size() - 1;
        int result = jobs.size();

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (jobs[mid][0] >= jobs[current_index][1]) {
                result = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return result;
    }

    int solve(int ind, vector<vector<int>>& jobs) {
        if (ind >= jobs.size()) return 0;

        if (dp[ind] != -1) return dp[ind];
        
        int not_take = solve(ind + 1, jobs);

        int next_ind = findNextJob(ind, jobs);
        int take = jobs[ind][2] + solve(next_ind, jobs);
        
        return dp[ind] = max(take, not_take);
    }

public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = profit.size();
        vector<vector<int>> jobs(n);

        for (int i = 0; i < n; ++i) {
            jobs[i] = {startTime[i], endTime[i], profit[i]};
        }

        sort(jobs.begin(), jobs.end());

        dp.assign(n, -1);

        return solve(0, jobs);
    }
};