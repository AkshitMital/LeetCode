class Solution {
public:
    int minDifference(vector<int>& nums) {
        int n = nums.size();
        if(n <= 4) return 0;
        partial_sort(nums.begin(), nums.begin()+4, nums.end());//O(nlog4)
        nth_element(nums.begin()+4, nums.begin()+(n-4), nums.end());//O(n)
        sort(nums.begin()+(n-4), nums.end());//O(4log4) = O(1)
        int op1 = nums[n-4] - nums[0];
        int op2 = nums[n-3] - nums[1];
        int op3 = nums[n-2] - nums[2];
        int op4 = nums[n-1] - nums[3];
        
        return min({op1,op2,op3,op4});
    }
};