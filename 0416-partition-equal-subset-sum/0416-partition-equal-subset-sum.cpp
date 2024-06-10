class Solution {
public:
    int solve(int i , vector<int> &arr , int sum , vector<vector<int>> &dp){
        
        if(sum==0) return 1;

        if(i==0 && sum != arr[0]) return 0;
        
        if(sum<0 || i<0 ) return 0;
        
        if(dp[i][sum] != -1) return dp[i][sum];
        
        // int take = solve(i-1,arr,sum-arr[i] , dp);
        
        // int nottake = solve(i-1,arr,sum, dp);
        
        int ans = solve(i-1,arr,sum-arr[i] , dp) || solve(i-1,arr,sum, dp)  ;
        
        // dp[i][sum] = ans;
        
        
        return dp[i][sum] = ans;
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int i=0;i<n;i++){
            sum = sum + nums[i];
        }

        if(sum%2==1) return 0;

        sum = sum /2;

        vector<vector<int>> dp(n+1,vector<int>(sum+1,-1));

        int ans = solve(n-1,nums,sum ,dp);

        return ans;

    }
};