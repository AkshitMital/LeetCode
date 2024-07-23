class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int profit=nums[0];
        int sum = 0;
        for(auto i:nums){
            if(sum < 0) sum = 0;
            sum += i;
            profit = max(profit, sum);
        }
        return max(sum, profit);
    }
};