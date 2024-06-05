// class Solution {
// private:
//     int solve(vector<int>& nums, int index, vector<int>& dp){
//         if(index == 0) return nums[index];
//         if(index < 0) return 0;
//         if(dp[index] != -1) return dp[index];
//         int pick = nums[index] + solve(nums, index - 2, dp);
//         int not_pick = 0 + solve(nums, index - 1, dp);

//         return dp[index] = max(pick, not_pick);
//     }
// public:
//     int rob(vector<int>& nums) {
//         vector<int> dp(nums.size(), -1);
//         return solve(nums, nums.size()-1, dp);
//     }
// };

class Solution {
public:
    int rob(vector<int>& nums) {
        int prev1 = nums[0], prev2 = 0;
        for(int i = 1; i < nums.size(); i++){
            int take = nums[i];
            if(i > 1) take += prev2;
            int not_take = 0 + prev1;
            int curr = max(take, not_take);
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
};