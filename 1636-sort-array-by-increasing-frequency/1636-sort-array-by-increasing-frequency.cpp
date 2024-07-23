class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int,int> mpp;
        for(int num : nums) mpp[num]++;

        auto lambda = [&](int a, int b){
            if(mpp[a] == mpp[b]) return b < a;
            return mpp[a] < mpp[b];
        };

        sort(nums.begin(), nums.end(), lambda);

        return nums;
    }
};