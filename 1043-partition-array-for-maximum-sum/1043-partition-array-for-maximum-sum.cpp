class Solution {
private:
    int solve(int i, vector<int>& arr, int k, int n, vector<int>& dp){
        if(i == n) return 0;
        if(dp[i] != -1) return dp[i];
        int len = 0, maxi = INT_MIN, maxSum = INT_MIN;
        for(int j = i; j < min(n, i + k); j++){
            len++;
            maxi = max(maxi, arr[j]);
            maxSum = max(maxSum, len*maxi + solve(j+1, arr, k, n, dp));
        }

        return dp[i] = maxSum;
    }
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n+1, -1);
        return solve(0, arr, k, n, dp);
    }
};

// class Solution {
// public:
//     int maxSumAfterPartitioning(vector<int>& arr, int k) {
//         int n = arr.size();
//         vector<int> dp(n+1, 0);

//         for(int i = n-1; i >= 0; i--){
//             int len = 0, maxi = INT_MIN, maxSum = INT_MIN;
//             for(int j = i; j < min(n, i+k); j++){
//                 len++;
//                 maxi = max(maxi, arr[j]);
//                 maxSum = max(maxSum, len*maxi + dp[j+1]);
//             }
//             dp[i] = maxSum;
//         }

//         return dp[0];
//     }
// };