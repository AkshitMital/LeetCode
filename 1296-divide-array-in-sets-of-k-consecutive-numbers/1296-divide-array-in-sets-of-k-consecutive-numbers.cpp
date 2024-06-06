class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        if(nums.size() % k != 0) return false;
        unordered_map<int,int> mpp;
        sort(nums.begin(), nums.end());
        for(auto it : nums) mpp[it]++;
        for(int i = 0; i < nums.size(); i++){
            if(!mpp[nums[i]]) continue;
            int j = k;
            int num = nums[i];
            while(j--){
                if(mpp[num]){
                    mpp[num]--;
                    num++;
                }
                else return false;
            }
        }

        return true;
    }
};