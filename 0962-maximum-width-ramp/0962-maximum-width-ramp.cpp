class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n = nums.size();
        vector<int> rightMax(n);
        rightMax[n-1] = nums[n-1];
        for(int i = n-2; i>=0; i--){
            rightMax[i] = max(nums[i], rightMax[i+1]);
        }
        int l = 0, r = 0, maxWidth = 0;
        while(r < n){
            while(l < r && nums[l] > rightMax[r]) l++;
            maxWidth = max(maxWidth, r - l);
            r++;
        }

        return maxWidth;
    }
};