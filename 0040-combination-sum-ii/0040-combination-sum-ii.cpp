class Solution {
    void solve(int idx, vector<int>& ds, vector<vector<int>>& ans, vector<int>& candidates, int target){
        if(target == 0){
            ans.push_back(ds);
            return;
        }

        for(int i = idx; i < candidates.size(); i++){
            if(i > idx && candidates[i] == candidates[i-1]) continue;
            if(candidates[i] > target) break;
            ds.push_back(candidates[i]);
            solve(i + 1, ds, ans, candidates, target - candidates[i]);
            ds.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> ds;
        vector<vector<int>> ans;
        solve(0, ds, ans, candidates, target);
        return ans;
    }
};