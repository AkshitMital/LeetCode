class Solution {
private:
    int KadaneMin(vector<int>& nums, int n){
        int sum = 0;
        int minSum = INT_MAX;
        for(int i = 0; i < n; i++){
            sum += nums[i];
            minSum = min(minSum, sum);
            if(sum > 0) sum = 0;
        }

        return minSum;
    }

    int KadaneMax(vector<int>& nums, int n){
        int sum = 0;
        int maxSum = INT_MIN;
        for(int i = 0; i < n; i++){
            sum += nums[i];
            maxSum = max(maxSum, sum);
            if(sum < 0) sum = 0;
        }

        return maxSum;
    }
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        int total = accumulate(nums.begin(), nums.end(), 0);

        int minSum = KadaneMin(nums, n);
        int maxSum = KadaneMax(nums, n);

        int circularSum = total - minSum;

        return (circularSum > 0) ? max(circularSum, maxSum) : maxSum;
    }
};