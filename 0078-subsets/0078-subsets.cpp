class Solution {
private:

void power_set(vector<int>& nums , vector<int>& ds , int i , int n, vector<vector<int>>& ans)
{
    // if(i >= n){
    //     ans.push_back(ds);
    //     return;
    // }

    // ds.push_back(nums[i]);
    // power_set(nums, ds, i+1, n, ans);
    // ds.pop_back();
    // power_set(nums, ds, i+1, n, ans);

    ans.push_back(ds);
    for(int j = i; j < n; j++){
        ds.push_back(nums[j]);
        power_set(nums, ds, j+1, n, ans);
        ds.pop_back();
    }
}

public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        int n = nums.size();
        power_set(nums,ds,0,n,ans);
        return ans;
    }
};