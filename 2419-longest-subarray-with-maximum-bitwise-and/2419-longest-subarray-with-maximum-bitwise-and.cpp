class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxVal = 0, res = 0, streak = 0;

        for(int& num : nums){
            if(num > maxVal){
                maxVal = num;
                res = 0;
                streak = 0;
            }

            if(num == maxVal) streak++;
            else streak = 0;
            
            res = max(res, streak);
        }

        return res;
    }
};