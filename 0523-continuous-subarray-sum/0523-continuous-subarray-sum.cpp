class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> mpp;
        int prefix = 0;
        mpp[0] = -1;
        for(int i = 0; i < n; i++){
            prefix += nums[i];
            int remain = prefix % k;
            if(mpp.find(remain) != mpp.end()){
                if(i - mpp[remain] >= 2) return true;
            }
            else mpp[remain] = i;
        }

        return false;
    }
};