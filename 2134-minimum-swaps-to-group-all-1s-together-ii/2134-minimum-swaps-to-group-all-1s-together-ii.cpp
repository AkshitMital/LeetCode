class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        int s = 0, e = 0, maxCount1 = 0, currCount1 = 0, totalCount1 = 0;

        for(auto num : nums){
            if(num == 1) totalCount1++;
        }

        while(e < totalCount1){
            if(nums[e++] == 1) currCount1++;
            maxCount1 = max(maxCount1, currCount1);
        }

        while(e < 2*n){
            if(nums[s%n] == 1) currCount1--;
            s++;
            if(nums[e%n] == 1) currCount1++;
            e++;
            maxCount1 = max(maxCount1, currCount1);
        }

        return totalCount1 - maxCount1;
    }
};