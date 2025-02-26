class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int n = nums.size();

        int currSumMax = nums[0], maxSum = nums[0];
        int currSumMin = nums[0], minSum = nums[0];
        for(int i = 1; i < n; i++) {
            currSumMax = max(nums[i], nums[i] + currSumMax);
            maxSum = max(maxSum, currSumMax);

            currSumMin = min(nums[i], nums[i] + currSumMin);
            minSum = min(minSum, currSumMin);
        }

        return max(abs(minSum), maxSum);
    }
};