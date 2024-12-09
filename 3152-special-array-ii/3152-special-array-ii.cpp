class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> prefixSum(n, 1);

        for(int i = 1; i < n; i++){
            if((nums[i] & 1) != (nums[i-1] & 1)) prefixSum[i] = 1 + prefixSum[i-1];
        }

        vector<bool> ans;
        for(auto query : queries){
            int start = query[0];
            int end = query[1];

            if(prefixSum[end] >= end - start + 1) ans.push_back(true);
            else ans.push_back(false);
        }

        return ans;
    }
};