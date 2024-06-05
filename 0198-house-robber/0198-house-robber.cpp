class Solution {
public:
    int rob(vector<int>& nums) {
        int prev1 = nums[0], prev2 = 0;
        for(int i = 1; i < nums.size(); i++){
            int take = nums[i];
            if(i > 1) take += prev2;
            int not_take = 0 + prev1;
            int curr = max(take, not_take);
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
};