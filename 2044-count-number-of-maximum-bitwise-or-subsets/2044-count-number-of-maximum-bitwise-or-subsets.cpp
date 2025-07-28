class Solution {
private:
    int solve(vector<int>& nums, int ind, int x, vector<vector<int>>& dp, int maxi){
        if(ind < 0) return (x == maxi) ? 1 : 0;

        if(dp[ind][x] != -1) return dp[ind][x];

        int tempxor = x | nums[ind];
        
        int exclude = solve(nums, ind-1, x, dp, maxi);
        int include = solve(nums, ind-1, tempxor, dp, maxi);

        return dp[ind][x] = include + exclude;
    }
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int n = nums.size();

        int maxi = 0;
        for(int num : nums) maxi |= num;

        vector<vector<int>> dp(n, vector<int>(maxi+1, -1));

        return solve(nums, n-1, 0, dp, maxi);
    }
};

class Solution {
private:
    int solve(vector<int>& nums, int ind, int x, vector<vector<int>>& dp, int maxi){
        if(ind < 0) return (x == maxi) ? 1 : 0;

        if(dp[ind][x] != -1) return dp[ind][x];

        int tempxor = x | nums[ind];
        
        int exclude = solve(nums, ind-1, x, dp, maxi);
        int include = solve(nums, ind-1, tempxor, dp, maxi);

        return dp[ind][x] = include + exclude;
    }
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int n = nums.size();

        int maxi = 0;
        for(int num : nums) maxi |= num;

        vector<vector<int>> dp(n, vector<int>(maxi+1, 0));
        dp[]

        for(int i)

        return dp[n-1][maxi];
    }
};