class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int> mpp;
        mpp[0] = 1;
        int prefix = 0;
        int ans = 0;
        for(int i = 0; i < nums.size(); i++){
            prefix += nums[i];
            int rem = prefix % k;
            if (rem < 0) rem += k;
            if(mpp.find(rem) != mpp.end()){
                ans += mpp[rem];
            }else{
                mpp[rem] = 0;
            }
            mpp[rem]++;
        }
        return ans;
    }

    // 4 5 0 -2 -3 1
    // 4 9 9 7 4 5
    // 4 4 4 2 4 0
    // 0 1 2 3 4 5

    // 1-0 2-0(2) 4-0(3) 5-0
};