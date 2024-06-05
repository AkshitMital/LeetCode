class Solution {
private:
    int rob1(vector<int>& nums) {
        int n = nums.size(), prev1 = nums[0], prev2 = 0;
        for(int i = 1; i < n; i++){
            int take = nums[i];
            if(i > 1) take += prev2;
            int not_take = 0 + prev1;
            int curr = max(take, not_take);
            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;
    }
public:
    int rob(vector<int>& nums) {
        vector<int> temp1, temp2;
        if(nums.size() == 1) return nums[0];
        for(int i = 1; i < nums.size(); i++){
            temp1.push_back(nums[i]);
        }
        for(int i = 0; i < nums.size()-1; i++){
            temp2.push_back(nums[i]);
        }
        return max(rob1(temp1),rob1(temp2));
    }
};