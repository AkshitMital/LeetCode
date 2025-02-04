class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int n = nums.size(), tempSum = nums[0], maxSum = nums[0];
        for(int i = 1; i < n; i++) {
            if(nums[i] > nums[i - 1]) tempSum += nums[i];
            else tempSum = nums[i];
            maxSum = max(tempSum, maxSum);
        }

        return maxSum;
    }
};