class Solution {
private:
    void solve(vector<int> temp, vector<vector<int>>& ans, vector<int>& nums, unordered_set<int>& st){
        if(temp.size() == nums.size()){
            ans.push_back(temp);
            return;
        }

        for(int i = 0; i < nums.size(); i++){
            if(st.find(nums[i]) == st.end()){
                temp.push_back(nums[i]);
                st.insert(nums[i]);
                solve(temp, ans, nums, st);
                temp.pop_back();
                st.erase(nums[i]);
            }
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        unordered_set<int> st;
        vector<int> temp;
        solve(temp, ans, nums, st);
        return ans;
    }
};