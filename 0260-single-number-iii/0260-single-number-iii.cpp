class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long long xorr=0;
        int b1 = 0, b2 = 0;
        for(int i = 0; i< nums.size(); i++){
            xorr ^= nums[i];
        }

        long long rightmost = xorr ^ (xorr & (xorr-1));
        for(int i = 0; i< nums.size(); i++){
            if(nums[i] & rightmost) b1 ^= nums[i];
            else b2 ^= nums[i];
        }

        return {b1, b2};
    }
};