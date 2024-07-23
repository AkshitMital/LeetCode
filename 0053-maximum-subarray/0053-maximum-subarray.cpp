class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = INT_MIN;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i-1] < 0) continue;
            nums[i] += nums[i-1];
        }
        
        for(int i = 0; i < nums.size(); i++){
            ans = max(ans, nums[i]);
        }

        return ans;
    }
};