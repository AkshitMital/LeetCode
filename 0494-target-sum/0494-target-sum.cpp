// class Solution {
// private:
//     int solve(int ind, vector<int>& nums, int target, vector<vector<int>>& dp){
//         if(ind == 0){
//             if(nums[0] == 0 && target == 0) return 2;
//             if(nums[0] == target || target == 0) return 1;
//             return 0;
//         }
//         if(dp[ind][target] != -1) return dp[ind][target];
//         int not_pick = solve(ind-1, nums, target, dp);
//         int pick = 0;
//         if(nums[ind] <= target) pick = solve(ind-1, nums, target-nums[ind], dp);

//         return dp[ind][target] = pick + not_pick;
//     }
// public:
//     int findTargetSumWays(vector<int>& nums, int target) {
//         int n = nums.size();
//         int totalsum = 0;
//         for(auto it : nums) totalsum += it;
//         if((totalsum - target) < 0 || (totalsum - target) % 2 != 0) return 0;
//         int k = (totalsum - target)/2;
//         vector<vector<int>> dp(n, vector<int>(k+1, -1));
//         return solve(n-1, nums, k, dp);
//     }
// };

// class Solution {
// public:
//     int findTargetSumWays(vector<int>& nums, int target) {
//         int n = nums.size();
//         int totalsum = 0;
//         for(auto it : nums) totalsum += it;
//         if((totalsum - target) < 0 || (totalsum - target) % 2 != 0) return 0;
//         int k = (totalsum - target)/2;

//         vector<vector<int>> dp(n, vector<int>(k+1, 0));

//         if(nums[0] == 0) dp[0][0] = 2;
//         else dp[0][0] = 1;

//         if(nums[0]!=0 && nums[0] <= k) dp[0][nums[0]] = 1;

//         for(int ind = 1; ind < n; ind++){
//             for(int sum = 0; sum <= k; sum++){
//                 int not_pick = dp[ind-1][sum];
//                 int pick = 0;
//                 if(nums[ind] <= sum) pick = dp[ind-1][sum - nums[ind]];

//                 dp[ind][sum] = not_pick + pick;
//             }
//         }

//         return dp[n-1][k];
//     }
// };

// class Solution {
// public:
//     int findTargetSumWays(vector<int>& nums, int target) {
//         int n = nums.size();
//         int totalsum = 0;
//         for(auto it : nums) totalsum += it;
//         if((totalsum - target) < 0 || (totalsum - target) % 2 != 0) return 0;
//         int k = (totalsum - target)/2;
        
//         vector<int> prev(k+1, 0), curr(k+1, 0);

//         if(nums[0] == 0) prev[0] = 2;
//         else prev[0] = 1;

//         if(nums[0]!=0 && nums[0] <= k) prev[nums[0]] = 1;

//         for(int ind = 1; ind < n; ind++){
//             for(int sum = 0; sum <= k; sum++){
//                 int not_pick = prev[sum];
//                 int pick = 0;
//                 if(nums[ind] <= sum) pick = prev[sum - nums[ind]];

//                 curr[sum] = not_pick + pick;
//             }
//             prev = curr;
//         }

//         return prev[k];
//     }
// };

class Solution {
private:
    int solve(vector<int>& nums, int ind, int target, vector<vector<int>>& dp){
        if(ind == 0){
            if(nums[0] == 0 && target == 0) return 2;
            if(nums[0] == target || target == 0) return 1;
            return 0;
        }
        if(dp[ind][target] != -1) return dp[ind][target];
        int not_take = solve(nums, ind - 1, target, dp);
        int take = 0;
        if(nums[ind] <= target) take = solve(nums, ind - 1, target - nums[ind], dp);

        return dp[ind][target] = take + not_take;
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int totalsum = 0;
        for(auto it : nums) totalsum += it;
        if((totalsum - target) < 0 || (totalsum - target) % 2 != 0) return 0;
        int k = (totalsum - target) / 2;
        vector<vector<int>> dp(n, vector<int>(k + 1, -1));
        
        return solve(nums, n - 1, k, dp);
    }
};