class Solution {
private:
    void solve(vector<int>& temp, unordered_set<int>& st, set<vector<int>>& Ansst, vector<int>& nums){
        if(temp.size() == nums.size()){
            Ansst.insert(temp);
            return;
        }

        for(int i = 0; i < nums.size(); i++){
            if(st.find(i) == st.end()){
                st.insert(i);
                temp.push_back(nums[i]);
                solve(temp, st, Ansst, nums);
                temp.pop_back();
                st.erase(i);
            }
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        unordered_set<int> st;
        set<vector<int>> Ansst;
        vector<int> temp;
        solve(temp, st, Ansst, nums);

        for(auto num : Ansst) ans.push_back(num);

        return ans;
    }
};