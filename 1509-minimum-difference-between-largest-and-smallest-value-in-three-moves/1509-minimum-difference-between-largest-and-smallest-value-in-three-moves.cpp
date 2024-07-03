class Solution {
public:
    int minDifference(vector<int>& nums) {
        int n = nums.size();
        if(n <= 4) return 0;
        sort(nums.begin(),nums.end());
        
        int op1 = nums[n-4] - nums[0];
        int op2 = nums[n-3] - nums[1];
        int op3 = nums[n-2] - nums[2];
        int op4 = nums[n-1] - nums[3];
        
        return min({op1,op2,op3,op4});
    }
};