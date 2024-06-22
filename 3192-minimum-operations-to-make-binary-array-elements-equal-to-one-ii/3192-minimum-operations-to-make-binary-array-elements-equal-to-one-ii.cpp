class Solution {
public:
    int minOperations(vector<int>& nums) {
        int ans = 0;
        bool flip = false;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == flip) {
                ans++;
                flip = !flip;
            }
        }

        return ans;
    }
};