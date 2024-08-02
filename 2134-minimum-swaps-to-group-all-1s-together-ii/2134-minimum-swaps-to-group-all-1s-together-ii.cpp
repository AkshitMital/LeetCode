class Solution {
private:
    int solve(vector<int>& nums, int val){
        int opp = !val;
        int total1 = 0;
        for(auto num : nums){
            if(num == val) total1++;
        }

        int s = 0, e = 0, curr = 0, ans = INT_MAX;

        while(e < total1){
            if(nums[e] == opp) curr++;
            ans = curr;
            e++;
        }

        while(e < nums.size()){
            if(nums[s++] == opp) curr--;
            if(nums[e++] == opp) curr++;
            ans = min(ans, curr);
        }

        return ans;
    }
public:
    int minSwaps(vector<int>& nums) {
        return min(solve(nums,1), solve(nums, 0));
    }
};