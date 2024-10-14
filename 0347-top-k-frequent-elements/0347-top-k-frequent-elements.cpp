class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<vector<int>> freq(nums.size() + 1);
        unordered_map<int,int> mpp;

        for(int num : nums) mpp[num]++;

        for(auto [num, f] : mpp) freq[f].push_back(num);

        vector<int> res;
        for(int i = freq.size()-1; i >= 0; i--){
            for(int num : freq[i]){
                res.push_back(num);
                if(res.size() == k) return res;
            }
        }

        return {};
    }
};