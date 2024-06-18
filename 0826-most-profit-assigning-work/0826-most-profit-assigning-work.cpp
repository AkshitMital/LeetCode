class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit,
                            vector<int>& worker) {
        vector<pair<int, int>> jobProfile;
        jobProfile.push_back({0, 0});
        for (int i = 0; i < difficulty.size(); i++) {
            jobProfile.push_back({profit[i], difficulty[i]});
        }

        // Sort in decreasing order of profit.
        sort(jobProfile.begin(), jobProfile.end());
        reverse(jobProfile.begin(), jobProfile.end());
        for (int i = 0; i < jobProfile.size() - 1; i++) {
            jobProfile[i + 1].second =
                min(jobProfile[i].second, jobProfile[i + 1].second);
        }

        int netProfit = 0;
        for (int i = 0; i < worker.size(); i++) {
            int ability = worker[i];
            // Maximize profit using binary search.
            int l = 0, r = jobProfile.size() - 1, jobProfit = 0;
            while (l <= r) {
                int mid = (l + r) / 2;
                if (jobProfile[mid].second <= ability) {
                    jobProfit = max(jobProfit, jobProfile[mid].first);
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            }
            // Add profit of each worker to total profit.
            netProfit += jobProfit;
        }
        return netProfit;
    }
};