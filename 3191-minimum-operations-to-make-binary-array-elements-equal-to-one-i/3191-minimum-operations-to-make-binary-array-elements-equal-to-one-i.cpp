class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int flipCount = 0;

        for(int i = 0; i < n - 2; i++){
            if(nums[i] == 0) {
                nums[i] = 1;
                nums[i + 1] = (nums[i + 1] == 0) ? 1 : 0;
                nums[i + 2] = (nums[i + 2] == 0) ? 1 : 0;
                flipCount++;
            }
        }

        if(nums[n - 2] == 0 || nums[n - 1] == 0) return -1;

        return flipCount;
    }
};