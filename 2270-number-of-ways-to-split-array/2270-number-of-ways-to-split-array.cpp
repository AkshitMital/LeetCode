class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n = nums.size();
        vector<long long> prefixSum(n, 0);
        prefixSum[0] = nums[0];
        for(int i = 1; i < n; i++) prefixSum[i] = prefixSum[i-1] + nums[i];
        
        int splits = 0;
        for(int i = 0; i < n - 1; i++){
            long long diff = prefixSum[n-1] - prefixSum[i];
            if(prefixSum[i] >= diff) splits++;
        }

        return splits;
    }
};