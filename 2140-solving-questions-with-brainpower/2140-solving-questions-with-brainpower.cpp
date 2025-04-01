// class Solution {
// private:
//     long long ans(int idx, vector<vector<int>>& questions, int n, vector<long long>& dp) {
//         if(idx >= n) return 0;
//         if(dp[idx] != -1) return dp[idx];

//         long long solve = questions[idx][0] + ans(idx + questions[idx][1] + 1, questions, n, dp);
//         long long skip = ans(idx + 1, questions, n, dp);

//         return dp[idx] = max(skip, solve);
//     }

// public:
//     long long mostPoints(vector<vector<int>>& questions) {
//         int n = questions.size();
//         vector<long long> dp(n+1, -1);
//         return ans(0, questions, n, dp);
//     }
// };

class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<long long> dp(n+1, 0);

        for(int idx = n - 1; idx >= 0; idx--) {
            long long solve = questions[idx][0] + ((idx + questions[idx][1] + 1 >= n) ? 0 : dp[idx + questions[idx][1] + 1]);
            long long skip = dp[idx + 1];
            dp[idx] = max(skip, solve);
        }

        return dp[0];
    }
};