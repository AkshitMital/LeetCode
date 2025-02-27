class Solution {
private:
    int solve(int j, int k, vector<int>& arr, unordered_map<int, int>& mpp, vector<vector<int>>& dp) {
        int diff = arr[k] - arr[j];

        if(mpp.find(diff) != mpp.end() && mpp[diff] < j) {
            int i = mpp[diff];
            return dp[j][k] = 1 + solve(i, j, arr, mpp, dp);
        }

        return dp[j][k] = 2;
    }

public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int ans = 0, n = arr.size();
        unordered_map<int, int> mpp;
        vector<vector<int>> dp(n, vector<int>(n, -1));

        for(int i = 0; i < n; i++) mpp[arr[i]] = i; 

        for(int j = 1; j < n; j++) {
            for(int k = j + 1; k < n; k++) {
                int length = solve(j, k, arr, mpp, dp);
                if(length >= 3) ans = max(ans, length);
            }
        }

        return ans;
    }
};