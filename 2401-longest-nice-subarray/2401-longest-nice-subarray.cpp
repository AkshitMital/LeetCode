class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int maxSize = 1, n = nums.size();

        int l = 0, r = 0, usedBits = 0;

        while(r < n) {
            while((usedBits & nums[r]) != 0) {
                usedBits ^= nums[l];
                l++;
            }

            maxSize = max(maxSize, r - l + 1);
            usedBits |= nums[r];
            r++;
        }

        return maxSize;
    }
};