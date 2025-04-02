class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        long long res = 0, dnum = 0, inum = 0;

        for(int k = 0; k < n; k++) {
            res = max(res, dnum * nums[k]);
            dnum = max(dnum, inum - nums[k]);
            inum = max(inum, static_cast<long long>(nums[k]));
        }

        return res;
    }
};