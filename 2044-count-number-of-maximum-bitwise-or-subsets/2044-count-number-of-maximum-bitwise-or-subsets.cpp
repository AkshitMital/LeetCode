class Solution {
private:
    void solve(vector<int>& nums, int ind, unordered_map<int,int>& mpp, int& maxi, int x){
        if(ind < 0) return;

        int tempxor = x | nums[ind];
        maxi = max(maxi, tempxor);
        mpp[tempxor]++;

        solve(nums, ind-1, mpp, maxi, x);
        solve(nums, ind-1, mpp, maxi, tempxor);
    }
public:
    int countMaxOrSubsets(vector<int>& nums) {
        unordered_map<int,int> mpp;
        int maxi = 0;
        solve(nums, nums.size()-1, mpp, maxi, 0);
        cout << maxi;
        return mpp[maxi];
    }
};