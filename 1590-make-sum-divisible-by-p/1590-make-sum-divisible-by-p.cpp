class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int sum = 0, n = nums.size();
        for(int& num : nums) sum = (sum + num)%p;
        int target = sum % p;
        if(target == 0) return 0;

        int ans = n;
        unordered_map<int,int> mpp;
        mpp[0] = -1;
        int curr = 0;

        for(int j = 0; j < n; j++){
            curr = (curr + nums[j]) % p;
            int prev = (curr - target + p) % p;
            if(mpp.find(prev) != mpp.end()){
                ans = min(ans, j - mpp[prev]);
            }
            mpp[curr] = j;
        }

        return ans == n ? -1 : ans;
    }
};