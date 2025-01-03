class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n = nums.size();
        long long rightSum = 0;
        for(int i = 0; i < n; i++) rightSum += nums[i];
        
        int splits = 0;
        long long currSum = 0;
        for(int i = 0; i < n - 1; i++){
            currSum += nums[i];
            long long diff = rightSum - currSum;
            if(currSum >= diff) splits++;
        }

        return splits;
    }
};