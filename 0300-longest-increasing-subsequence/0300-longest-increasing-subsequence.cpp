// class Solution {
// private:
//     int solve(int ind, int prev, vector<int>& nums, vector<vector<int>>& dp){
//         if(ind == nums.size()) return 0;

//         if(dp[ind][prev+1] != -1) return dp[ind][prev+1];

//         int len = 0 + solve(ind+1, prev, nums, dp);
//         if(prev == -1 || nums[ind] > nums[prev]) 
//             len = max(len, 1 + solve(ind+1, ind, nums, dp));

//         return dp[ind][prev+1] = len;
//     }
// public:
//     int lengthOfLIS(vector<int>& nums) {
//         int n = nums.size();
//         vector<vector<int>> dp(n, vector<int>(n+1, -1));
//         return solve(0, -1, nums, dp);
//     }
// };

// class Solution {
// public:
//     int lengthOfLIS(vector<int>& nums) {
//         int n = nums.size();
//         vector<vector<int>> dp(n+1, vector<int>(n+1, 0));

//         for(int ind = n-1; ind >= 0; ind--){
//             for(int prev = ind-1; prev >= -1; prev--){
//                 int len = 0 + dp[ind+1][prev+1];
//                 if(prev == -1 || nums[ind] > nums[prev]) 
//                     len = max(len, 1 + dp[ind+1][ind+1]);

//                 dp[ind][prev+1] = len;
//             }
//         }

//         return dp[0][-1+1];
//     }
// };

// class Solution {
// public:
//     int lengthOfLIS(vector<int>& nums) {
//         int n = nums.size();
//         vector<int> next(n+1, 0), curr(n+1, 0);

//         for(int ind = n-1; ind >= 0; ind--){
//             for(int prev = ind-1; prev >= -1; prev--){
//                 int len = 0 + next[prev+1];
//                 if(prev == -1 || nums[ind] > nums[prev]) 
//                     len = max(len, 1 + next[ind+1]);

//                 curr[prev+1] = len;
//             }
//             next = curr;
//         }

//         return next[-1+1];
//     }
// };

// class Solution {
// public:
//     int lengthOfLIS(vector<int>& nums) {
//         int n = nums.size();
//         vector<int> dp(n,1);

//         for(int i = 0; i < n; i++){
//             for(int prev = 0; prev < i; prev++){
//                 if(nums[prev] < nums[i]){
//                     dp[i] = max(dp[i], 1 + dp[prev]);
//                 }
//             }
//         }

//         int ans = *max_element(dp.begin(), dp.end());

//         return ans;
//     }
// };

class Solution {
public:
    int lengthOfLIS(vector<int>& arr) {
        int n = arr.size();
        vector<int> temp;
        temp.push_back(arr[0]);
        for(int i = 1; i < n; i++){
            if(arr[i] > temp.back()){
                temp.push_back(arr[i]);
            }else{
                int ind = lower_bound(temp.begin(), temp.end(), arr[i]) - temp.begin();
                temp[ind] = arr[i];
            }
        }

        return temp.size();
    }
};