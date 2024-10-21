class Solution {
private:
    void solve(int ind, vector<vector<int>>& ans, vector<int>& nums){
        if(ind == nums.size()){
            ans.push_back(nums);
            return;
        }

        unordered_set<int> st;
        for(int j = ind; j < nums.size(); j++){
            if(st.find(nums[j]) != st.end()) continue;
            st.insert(nums[j]);
            swap(nums[j], nums[ind]);
            solve(ind+1, ans, nums);
            swap(nums[j], nums[ind]);
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        unordered_set<int> st;
        vector<vector<int>> ans;
        solve(0, ans, nums);

        return ans;
    }
};