class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        int temp = 1;
        vector<int> ans(n, 1);
        
        for (int i = 0; i < n; i++) { 
            ans[i] = temp;
            // cout<<ans[i]<<" ";
            temp *= nums[i];
        }
        // 1 1 2 6
        // cout<<endl;
        
        temp = 1;
        for (int i = n - 1; i >= 0; i--) { 
            ans[i] *= temp;
            // cout<<ans[i]<<" ";
            temp *= nums[i]; 
        } 
        // 24 12 8 6

        return ans;
    }
};