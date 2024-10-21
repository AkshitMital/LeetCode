class Solution {
private:
    void solve(int ind, vector<int> nums, vector<vector<int>>& ans){
        if(ind == nums.size()){
            ans.push_back(nums);
            return;
        }
        for(int i = ind; i < nums.size(); i++){
            if(i!=ind && nums[i] == nums[ind]) continue;
            swap(nums[ind], nums[i]);
            solve(ind+1, nums, ans);
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        solve(0, nums, ans);
        return ans;
    }
};