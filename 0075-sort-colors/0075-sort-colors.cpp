class Solution {
public:
    void sortColors(vector<int>& nums) {
        unordered_map<int,int> mpp;
        for(auto num : nums) mpp[num]++;

        vector<int> ans;

        for(int i = 0; i < 3; i++){
            while(mpp[i]){
                ans.push_back(i);
                mpp[i]--;
            }
        }

        nums = ans;

        // for(int i = 0; i < nums.size(); i++){
        //     while(mpp[0]){
        //         nums[i] = 0;
        //         mpp[0]--;
        //     }
        //     while(mpp[1]){
        //         nums[i] = 0;
        //         mpp[0]--;
        //     }
        //     while(mpp[2]){
        //         nums[i] = 0;
        //         mpp[0]--;
        //     }
        // }
    }
};