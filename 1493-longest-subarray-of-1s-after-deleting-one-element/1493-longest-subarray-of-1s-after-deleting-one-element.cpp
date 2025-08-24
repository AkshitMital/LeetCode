class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int j = 0, res = 0, n = nums.size(), totalZero = 0;
        for(int i = 0; i < n; i++) {
            if(nums[i] == 0) totalZero++;

            while(totalZero > 1) {
                if(nums[j] == 0) totalZero--;
                j++;
            }

            res = max(res, i - j);
        }

        return res;
    }
};