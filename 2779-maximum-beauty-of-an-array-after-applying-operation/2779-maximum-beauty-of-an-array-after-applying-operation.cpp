class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        int l = 0, r = 0, n = nums.size();
        sort(nums.begin(), nums.end());
        int res = 0;
        while(l <= r && r < n){
            int maxNum = nums[l] + 2 * k;
            while(r < n && nums[r] <= maxNum) r++;
            res = max(res, r - l);
            if(l < r) l++;
        }

        return res;
    }
};