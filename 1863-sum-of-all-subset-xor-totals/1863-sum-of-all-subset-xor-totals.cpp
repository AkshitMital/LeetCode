class Solution {
private:
    void solve(int index, int n, vector<int>& nums, vector<int>& vec, int& ans){
        if(index == n){
            int XOR = 0;
            for(auto num : vec){
                XOR ^= num;
            }
            ans += XOR;
            return;
        }
        vec.push_back(nums[index]);
        solve(index + 1, n, nums, vec, ans);
        vec.pop_back();
        solve(index + 1, n, nums, vec, ans);
    }
public:
    int subsetXORSum(vector<int>& nums) {
        vector<int> vec;
        int ans = 0;
        solve(0, nums.size(),nums, vec, ans);
        return ans;
    }
};

// class Solution {
// public:
//     int subsetXORSum(vector<int>& nums) {
//         int n = nums.size();
//         int subsetcnt = 1 << n ; 
//         int ans = 0;

//         for(int i = 0; i < subsetcnt; i++){
//             int XOR = 0;
//             for(int j = 0; j < n; j++){
//                 if(i & (1<<j)){
//                     XOR ^= nums[j];
//                 }
//             }
//             ans += XOR;
//         }

//         return ans;
//     }
// };