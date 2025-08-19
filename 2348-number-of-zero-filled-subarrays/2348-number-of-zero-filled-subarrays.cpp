class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        int n = nums.size();
        long long res = 0;

        for(int i = 0; i < n; i++) {
            if(nums[i] == 0) {
                int j = i + 1;
                while(j < n && nums[j] == 0) {
                    j++;
                }
                long long dist = j - i;
                res += (dist * (dist + 1) / 2);
                i = j;
            }
        }

        return res;
    }
};